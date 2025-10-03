#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int x, y, broken;
};

int N, M, K;
int grid[1001][1001];
int dist[1001][1001][11]; // K 최대 10까지 가능
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int bfs()
{
    queue<Node> q;
    q.push({0, 0, 0});
    dist[0][0][0] = 1;

    while (!q.empty())
    {
        Node cur = q.front();
        q.pop();

        int x = cur.x;
        int y = cur.y;
        int b = cur.broken;

        if (x == N - 1 && y == M - 1)
        {
            return dist[x][y][b];
        }

        for (int d = 0; d < 4; d++)
        {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;

            // 빈 칸
            if (grid[nx][ny] == 0 && dist[nx][ny][b] == 0)
            {
                dist[nx][ny][b] = dist[x][y][b] + 1;
                q.push({nx, ny, b});
            }
            // 벽이고, 아직 부술 기회가 남아있을 때
            else if (grid[nx][ny] == 1 && b < K && dist[nx][ny][b + 1] == 0)
            {
                dist[nx][ny][b + 1] = dist[x][y][b] + 1;
                q.push({nx, ny, b + 1});
            }
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
