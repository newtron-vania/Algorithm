#include <bits/stdc++.h>

using namespace std;

int n, k, r;
vector<pair<int, int>> road[101][101];
bool cow_visit[101][101];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void bfs(int r1, int c1)
{
    queue<pair<int, int>> q;
    q.push({r1, c1});
    cow_visit[r1][c1] = true;

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        for (int d = 0; d < 4; d++)
        {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (cow_visit[nx][ny]) continue;

            bool blocked = false;
            for (auto &p : road[x][y])
            {
                if (p.first == nx && p.second == ny)
                {
                    blocked = true;
                    break;
                }
            }
            if (blocked) continue;

            cow_visit[nx][ny] = true;
            q.push({nx, ny});
        }
    }
}

int main()
{
    scanf("%d %d %d", &n, &k, &r);

    for (int i = 0; i < r; i++)
    {
        int r1, c1, r2, c2;
        scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
        r1--, c1--, r2--, c2--;
        road[r1][c1].push_back({r2, c2});
        road[r2][c2].push_back({r1, c1});
    }

    vector<pair<int, int>> cow_list;
    for (int i = 0; i < k; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        cow_list.push_back({a - 1, b - 1});
    }

    int count = 0;
    for (int i = 0; i < k; i++)
    {
        memset(cow_visit, false, sizeof(cow_visit));
        bfs(cow_list[i].first, cow_list[i].second);

        for (int j = i + 1; j < k; j++)
        {
            if (!cow_visit[cow_list[j].first][cow_list[j].second])
            {
                count++;
            }
        }
    }

    printf("%d\n", count);
    return 0;
}
