#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> graph[1001];
int visited[1001];

int bfs(int start, int target)
{
    queue<pair<int, int>> q;
    q.push({start, 0});
    visited[start] = 1;

    while (!q.empty())
    {
        int cur = q.front().first;
        int dist = q.front().second;
        q.pop();

        if (cur == target)
        {
            return dist;
        }

        for (auto &next : graph[cur])
        {
            int nx = next.first;
            int cost = next.second;

            if (!visited[nx])
            {
                visited[nx] = 1;
                q.push({nx, dist + cost});
            }
        }
    }

    return -1;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n - 1; i++)
    {
        int a, b, d;
        scanf("%d %d %d", &a, &b, &d);
        graph[a].push_back({b, d});
        graph[b].push_back({a, d});
    }

    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        memset(visited, 0, sizeof(visited));
        printf("%d\n", bfs(u, v));
    }

    return 0;
}
