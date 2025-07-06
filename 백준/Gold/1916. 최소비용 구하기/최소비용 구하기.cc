#include <bits/stdc++.h>

using namespace std;

const long INF = 9876543210;

long dijkstra(int start, int end, const vector<vector<pair<int, int>>>& nodes, int n)
{
    vector<long> dist(n + 1, INF);
    priority_queue<pair<long, int>, vector<pair<long, int>>, greater<>> pq;
    pq.push({0, start});
    dist[start] = 0;
    
    while (!pq.empty())
    {
        auto [cWeight, cNode] = pq.top();
        pq.pop();
        
        if (dist[cNode] < cWeight) continue;
        
        for (const auto& [nNode, nWeight] : nodes[cNode])
        {
            long w = cWeight + nWeight;
            if (dist[nNode] > w)
            {
                dist[nNode] = w;
                pq.push({w, nNode});
            }
        }
    }
    
    return dist[end] == INF ? -1 : dist[end];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    vector<vector<pair<int, int>>> nodes(n + 1);
    
    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        nodes[x].push_back({y, w});
    }
    
    int start, end;
    cin >> start >> end;
    
    long result = dijkstra(start, end, nodes, n);
    cout << result << '\n';
}