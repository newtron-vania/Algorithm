#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int x, y;
};

int N, M;
vector<Edge> sw[101][101];
bool light_on[101][101];
bool visited[101][101];
bool reachable[101][101];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main()
{
    scanf("%d %d", &N, &M);

    for (int i = 0; i < M; i++)
    {
        int x, y, a, b;
        scanf("%d %d %d %d", &x, &y, &a, &b);
        sw[x][y].push_back({a, b});
    }

    queue<pair<int, int>> q;
    q.push({1, 1});
    light_on[1][1] = true;
    visited[1][1] = true;
    reachable[1][1] = true;

    int ans = 1;

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        // 현재 방에서 불 켜기
        for (auto &e : sw[x][y])
        {
            if (!light_on[e.x][e.y])
            {
                light_on[e.x][e.y] = true;
                ans++;

                // 만약 인접한 방이 이미 방문 가능하다면 큐에 push
                for (int d = 0; d < 4; d++)
                {
                    int nx = e.x + dx[d];
                    int ny = e.y + dy[d];
                    if (nx >= 1 && ny >= 1 && nx <= N && ny <= N)
                    {
                        if (visited[nx][ny])
                        {
                            q.push({e.x, e.y});
                            visited[e.x][e.y] = true;
                            break;
                        }
                    }
                }
            }
        }

        // 인접한 불 켜진 방 이동
        for (int d = 0; d < 4; d++)
        {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 1 || ny < 1 || nx > N || ny > N) continue;
            if (visited[nx][ny]) continue;
            if (!light_on[nx][ny]) continue;

            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }

    printf("%d\n", ans);
    return 0;
}
