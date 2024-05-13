#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const long long INF = numeric_limits<long long>::max();


void Dijkstra(int start, vector<vector<pair<int, int>>>& nodes, vector<long long>& dp)
{
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> heap;
    dp[start] = 0;
    heap.push({0, start});

    while (!heap.empty())
    {
        auto [kdist, node] = heap.top();
        heap.pop();

        if (dp[node] < kdist)
        {
            continue;
        }

        for (auto& [w, next_node] : nodes[node])
        {
            long long next_dist = kdist + w;
            if (next_dist < dp[next_node])
            {
                dp[next_node] = next_dist;
                heap.push({next_dist, next_node});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<pair<int, int>>> nodes(n + 1);
    vector<long long> dp(n + 1, INF);

    for (int i = 0; i < m; i++)
    {
        int a, b, dist;
        cin >> a >> b >> dist;
        bool found = false;
        for (auto& edge : nodes[a])
        {
            if (edge.second == b)
            {
                found = true;
                edge.first = min(edge.first, dist);  // Keep only the smallest distance
                break;
            }
        }
        if (!found)
        {
            nodes[a].push_back({dist, b});
        }
    }

    Dijkstra(k, nodes, dp);

    for (int i = 1; i <= n; i++)
    {
        if (dp[i] == INF)
        {
            cout << "INF\n";
        }
        else
        {
            cout << dp[i] << '\n';
        }
    }

    return 0;
}
