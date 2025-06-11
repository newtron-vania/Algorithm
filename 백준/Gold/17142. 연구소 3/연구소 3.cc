#include <bits/stdc++.h>

using namespace std;

int N, M;
int lab[50][50];
int emptyCount = 0;
int minTime = INT_MAX;

vector<pair<int, int>> virus;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void input()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> lab[i][j];
            if (lab[i][j] == 2)
            {
                virus.push_back({ i, j });
            }
            else if (lab[i][j] == 0)
            {
                emptyCount++;
            }
        }
    }
}

void bfs(vector<pair<int, int>> active)
{
    int visited[50][50] = { 0 };
    queue<pair<int, int>> q;

    for (auto& v : active)
    {
        q.push(v);
        visited[v.first][v.second] = 1;
    }

    int time = 0;
    int infected = 0;

    while (!q.empty())
    {
        int sz = q.size();
        while (sz--)
        {
            auto [x, y] = q.front(); q.pop();

            for (int d = 0; d < 4; d++)
            {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
                if (visited[nx][ny] || lab[nx][ny] == 1) continue;

                visited[nx][ny] = 1;
                q.push({ nx, ny });

                if (lab[nx][ny] == 0)
                {
                    infected++;
                }
            }
        }

        time++;

        if (infected == emptyCount)
        {
            minTime = min(minTime, time);
            return;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    input();

    if (emptyCount == 0)
    {
        cout << 0 << '\n';
        return 0;
    }

    vector<int> select(virus.size(), 0);
    fill(select.end() - M, select.end(), 1);

    do
    {
        vector<pair<int, int>> active;
        for (int i = 0; i < virus.size(); i++)
        {
            if (select[i])
            {
                active.push_back(virus[i]);
            }
        }
        bfs(active);
    }
    while (next_permutation(select.begin(), select.end()));

    cout << (minTime == INT_MAX ? -1 : minTime) << '\n';

    return 0;
}
