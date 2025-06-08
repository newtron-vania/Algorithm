#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int n, m;
vector<vector<pair<int, int>>> graph;
vector<int> dist, prev_city;

void input()
{
    cin >> n >> m;
    graph.resize(n + 1);

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }
}

void dijkstra(int start)
{
    dist.assign(n + 1, INF);
    prev_city.assign(n + 1, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        auto [cost, now] = pq.top();
        pq.pop();

        if (dist[now] < cost)
            continue;

        for (auto [next, weight] : graph[now])
        {
            if (dist[next] > cost + weight)
            {
                dist[next] = cost + weight;
                prev_city[next] = now;
                pq.push({dist[next], next});
            }
        }
    }
}

void print_path(int end)
{
    vector<int> path;
    for (int at = end; at != -1; at = prev_city[at])
    {
        path.push_back(at);
    }
    reverse(path.begin(), path.end());

    cout << dist[end] << '\n';
    cout << path.size() << '\n';
    for (int city : path)
    {
        cout << city << ' ';
    }
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input();

    int start, end;
    cin >> start >> end;

    dijkstra(start);
    print_path(end);

    return 0;
}