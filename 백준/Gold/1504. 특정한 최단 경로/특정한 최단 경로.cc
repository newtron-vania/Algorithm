#include <bits/stdc++.h>

using namespace std;

const int INF = INT_MAX;

int n, m;
vector<vector<pair<int, int>>> nodes;

vector<int> Dijkstra(int start)
{
    vector<int> dp(n + 1, INF);
    dp[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, start});

    while (!pq.empty())
    {
        auto [kdist, node] = pq.top();
        pq.pop();

        if (dp[node] < kdist)
        {
            continue;
        }

        for (auto [w, next_node] : nodes[node])
        {
            int next_dist = kdist + w;
            if (next_dist < dp[next_node])
            {
                dp[next_node] = next_dist;
                pq.push({next_dist, next_node});
            }
        }
    }

    return dp;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    nodes.resize(n + 1);

    for (int i = 0; i < m; i++)
    {
        int a, b, dist;
        cin >> a >> b >> dist;
        nodes[a].emplace_back(dist, b);
        nodes[b].emplace_back(dist, a);
    }

    int v1, v2;
    cin >> v1 >> v2;

    vector<int> start = Dijkstra(1);
    vector<int> vec1 = Dijkstra(v1);
    vector<int> vec2 = Dijkstra(v2);

    long long path1 = (long long)start[v1] + vec1[v2] + vec2[n];
    long long path2 = (long long)start[v2] + vec2[v1] + vec1[n];
    long long ans = min(path1, path2);

    cout << (ans >= INF ? -1 : ans) << '\n';

    return 0;
}
