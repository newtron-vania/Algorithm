#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int x, y, broken, dayNight; // dayNight: 0=낮, 1=밤
};

int N, M, K;
int grid[1001][1001];
bool visited[1001][1001][11][2];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int bfs()
{
    queue<pair<Node, int>> q;
    q.push({{0, 0, 0, 0}, 1});
    visited[0][0][0][0] = true;

    while (!q.empty())
    {
        Node cur = q.front().first;
        int dist = q.front().second;
        q.pop();

        if (cur.x == N - 1 && cur.y == M - 1)
        {
            return dist;
        }

        for (int d = 0; d < 4; d++)
        {
            int nx = cur.x + dx[d];
            int ny = cur.y + dy[d];

            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;

            // 빈 칸 이동
            if (grid[nx][ny] == 0 && !visited[nx][ny][cur.broken][1 - cur.dayNight])
            {
                visited[nx][ny][cur.broken][1 - cur.dayNight] = true;
                q.push({{nx, ny, cur.broken, 1 - cur.dayNight}, dist + 1});
            }
            // 벽 부수기 (낮일 때만)
            else if (grid[nx][ny] == 1 && cur.broken < K && cur.dayNight == 0
                     && !visited[nx][ny][cur.broken + 1][1 - cur.dayNight])
            {
                visited[nx][ny][cur.broken + 1][1 - cur.dayNight] = true;
                q.push({{nx, ny, cur.broken + 1, 1 - cur.dayNight}, dist + 1});
            }
        }

        // 밤에는 제자리 대기 가능
        if (!visited[cur.x][cur.y][cur.broken][1 - cur.dayNight])
        {
            visited[cur.x][cur.y][cur.broken][1 - cur.dayNight] = true;
            q.push({{cur.x, cur.y, cur.broken, 1 - cur.dayNight}, dist + 1});
        }
    }
    return -1;
}

int main()
{
    scanf("%d %d %d", &N, &M, &K);
    for (int i = 0; i < N; i++)
    {
        char line[1005];
        scanf("%s", line);
        for (int j = 0; j < M; j++)
        {
            grid[i][j] = line[j] - '0';
        }
    }

    printf("%d\n", bfs());
    return 0;
}
