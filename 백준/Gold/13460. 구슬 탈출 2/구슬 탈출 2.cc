#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<char>> board;
int dx[4] = {-1, 1, 0, 0}; // 상, 하, 좌, 우
int dy[4] = {0, 0, -1, 1};

struct State
{
    int rx, ry, bx, by, depth;
};

pair<pair<int, int>, int> move(int x, int y, int dx, int dy, const vector<vector<char>> &board)
{
    int count = 0;
    while (board[x + dx][y + dy] != '#' && board[x][y] != 'O')
    {
        x += dx;
        y += dy;
        count++;
    }
    return {{x, y}, count};
}

int bfs(pair<int, int> red, pair<int, int> blue)
{
    queue<State> q;
    set<tuple<int, int, int, int>> visited;
    q.push({red.first, red.second, blue.first, blue.second, 0});
    visited.insert({red.first, red.second, blue.first, blue.second});

    while (!q.empty())
    {
        State cur = q.front();
        q.pop();

        if (cur.depth >= 10)
            break;

        for (int i = 0; i < 4; i++)
        {
            auto [next_red, red_count] = move(cur.rx, cur.ry, dx[i], dy[i], board);
            auto [next_blue, blue_count] = move(cur.bx, cur.by, dx[i], dy[i], board);

            int nrx = next_red.first, nry = next_red.second;
            int nbx = next_blue.first, nby = next_blue.second;

            if (board[nbx][nby] == 'O')
                continue;

            if (board[nrx][nry] == 'O')
                return cur.depth + 1;

            if (nrx == nbx && nry == nby)
            {
                if (red_count > blue_count)
                {
                    nrx -= dx[i];
                    nry -= dy[i];
                }
                else
                {
                    nbx -= dx[i];
                    nby -= dy[i];
                }
            }

            if (visited.count({nrx, nry, nbx, nby}) == 0)
            {
                visited.insert({nrx, nry, nbx, nby});
                q.push({nrx, nry, nbx, nby, cur.depth + 1});
            }
        }
    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    board.resize(n, vector<char>(m));
    pair<int, int> red, blue;

    for (int i = 0; i < n; i++)
    {
        string line;
        cin >> line;
        for (int j = 0; j < m; j++)
        {
            board[i][j] = line[j];
            if (board[i][j] == 'R') red = {i, j};
            else if (board[i][j] == 'B') blue = {i, j};
        }
    }

    int result = bfs(red, blue);
    cout << result << '\n';

    return 0;
}
