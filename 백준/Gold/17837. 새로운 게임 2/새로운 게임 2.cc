#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 14;
const int MAX_K = 11;
const int WHITE = 0;
const int RED = 1;
const int BLUE = 2;

const int dx[] = { 0, 0, 0, -1, 1 };
const int dy[] = { 0, 1, -1, 0, 0 };

struct Token
{
    int x, y, dir;
};

int N, K;
int color[MAX_N][MAX_N];
int board[MAX_N][MAX_N][MAX_K];
int length[MAX_N][MAX_N];
Token token[MAX_K];

inline bool inBounds(int x, int y)
{
    return 0 < x && x <= N && 0 < y && y <= N;
}

int findIndex(int x, int y, int id)
{
    for (int i = 0; i < MAX_K; i++)
    {
        if (board[x][y][i] == id)
        {
            return i;
        }
    }
    return -1;
}

void reverseTokens(int x, int y, int start)
{
    stack<int> s;
    int len = length[x][y];

    for (int i = start; i < len; i++)
    {
        s.push(board[x][y][i]);
    }

    int idx = start;
    while (!s.empty())
    {
        board[x][y][idx++] = s.top();
        s.pop();
    }
}

bool moveTokens()
{
    for (int k = 1; k <= K; k++)
    {
        int x = token[k].x;
        int y = token[k].y;
        int dir = token[k].dir;
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (!inBounds(nx, ny) || color[nx][ny] == BLUE)
        {
            if (dir == 1) dir = 2;
            else if (dir == 2) dir = 1;
            else if (dir == 3) dir = 4;
            else if (dir == 4) dir = 3;

            token[k].dir = dir;
            nx = x + dx[dir];
            ny = y + dy[dir];

            if (!inBounds(nx, ny) || color[nx][ny] == BLUE)
            {
                continue;
            }
        }

        int idx = findIndex(x, y, k);
        int fromEnd = length[x][y];
        int toEnd = length[nx][ny];

        for (int i = idx; i < fromEnd; i++)
        {
            int t = board[x][y][i];
            board[x][y][i] = 0;
            board[nx][ny][toEnd++] = t;
            token[t].x = nx;
            token[t].y = ny;
        }

        if (toEnd >= 4)
        {
            return false;
        }

        length[x][y] = idx;
        length[nx][ny] = toEnd;

        if (color[nx][ny] == RED)
        {
            reverseTokens(nx, ny, toEnd - (fromEnd - idx));
        }
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> K;

    for (int r = 1; r <= N; r++)
    {
        for (int c = 1; c <= N; c++)
        {
            cin >> color[r][c];
        }
    }

    for (int k = 1; k <= K; k++)
    {
        int x, y, dir;
        cin >> x >> y >> dir;
        board[x][y][0] = k;
        length[x][y]++;
        token[k] = { x, y, dir };
    }

    int turn;
    bool finished = false;

    for (turn = 1; turn <= 1000; turn++)
    {
        if (!moveTokens())
        {
            finished = true;
            break;
        }
    }

    cout << (finished ? turn : -1) << '\n';
    return 0;
}
