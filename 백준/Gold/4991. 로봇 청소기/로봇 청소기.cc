#include <bits/stdc++.h>
using namespace std;

int n, m;
char rawmap[25][25];
int graphv[25][25]; // -1 = 벽, 0 = 빈칸, 먼지 = bitmask
bool visited[1<<10][25][25];

struct Node
{
    int dust;
    int x;
    int y;
    int t;
};

int bfs(int sx, int sy, int cnt)
{
    int dir[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} };
    memset(visited, false, sizeof(visited));

    visited[0][sx][sy] = true;

    queue<Node> q;
    q.push({0, sx, sy, 0});

    while (!q.empty())
    {
        Node cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nd = cur.dust;
            int nx = cur.x + dir[i][0];
            int ny = cur.y + dir[i][1];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;
            if (visited[nd][nx][ny])
                continue;
            if (graphv[nx][ny] == -1) // 벽
                continue;

            // 먼지라면 비트 추가
            if (graphv[nx][ny] > 0)
                nd = cur.dust | graphv[nx][ny];

            visited[nd][nx][ny] = true;
            q.push({nd, nx, ny, cur.t + 1});

            // 먼지 count개를 모두 모았는가?
            if (__builtin_popcount(nd) == cnt)
                return cur.t + 1;
        }
    }
    return -1;
}

int main()
{
    while (true)
    {
        scanf("%d %d", &m, &n);
        if (n == 0 && m == 0)
            break;

        int sx = 0, sy = 0;
        int cnt = 0;

        for (int i = 0; i < n; i++)
        {
            scanf("%s", rawmap[i]);
        }

        memset(graphv, 0, sizeof(graphv));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (rawmap[i][j] == 'x')
                {
                    graphv[i][j] = -1;
                }
                else if (rawmap[i][j] == '*')
                {
                    graphv[i][j] = (1 << cnt);
                    cnt++;
                }
                else if (rawmap[i][j] == 'o')
                {
                    sx = i;
                    sy = j;
                    graphv[i][j] = 0;
                }
                else
                {
                    graphv[i][j] = 0;
                }
            }
        }

        int ans = bfs(sx, sy, cnt);
        printf("%d\n", ans);
    }
}
