#include <bits/stdc++.h>

using namespace std;

int n, m, k;
int maps[21][21];

int dx[4] = {0, 1, 0, -1}; 
int dy[4] = {1, 0, -1, 0};
int dice[6] = {1, 2, 3, 4, 5, 6};

void rolling_dice(int d)
{
    int temp[6];
    for (int i = 0; i < 6; i++) temp[i] = dice[i];

    if (d == 0) // 동쪽
    {
        dice[0] = temp[3];
        dice[2] = temp[0];
        dice[3] = temp[5];
        dice[5] = temp[2];
    }
    else if (d == 1) // 남쪽
    {
        dice[0] = temp[1];
        dice[1] = temp[5];
        dice[4] = temp[0];
        dice[5] = temp[4];
    }
    else if (d == 2) // 서쪽
    {
        dice[0] = temp[2];
        dice[2] = temp[5];
        dice[3] = temp[0];
        dice[5] = temp[3];
    }
    else // 북쪽
    {
        dice[0] = temp[4];
        dice[1] = temp[0];
        dice[4] = temp[5];
        dice[5] = temp[1];
    }
}

int bfs(int sx, int sy)
{
    bool visited[21][21];
    memset(visited, false, sizeof(visited));
    queue<pair<int, int>> q;
    q.push({sx, sy});
    visited[sx][sy] = true;

    int num = maps[sx][sy];
    int cnt = 1;

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (visited[nx][ny]) continue;
            if (maps[nx][ny] == num)
            {
                cnt++;
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
    return cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> maps[i][j];
        }
    }

    int x = 0, y = 0, d = 0;
    int score = 0;

    for (int step = 0; step < k; step++)
    {
        int nx = x + dx[d];
        int ny = y + dy[d];

        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
        {
            d = (d + 2) % 4; 
            nx = x + dx[d];
            ny = y + dy[d];
        }

        rolling_dice(d);
        int b = maps[nx][ny];
        int c = bfs(nx, ny);
        score += b * c;

        if (dice[5] > maps[nx][ny])
        {
            d = (d + 1) % 4; 
        }
        else if (dice[5] < maps[nx][ny])
        {
            d = (d + 3) % 4; 
        }

        x = nx;
        y = ny;
    }

    cout << score << "\n";
    return 0;
}