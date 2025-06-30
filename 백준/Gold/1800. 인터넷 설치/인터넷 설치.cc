#include <bits/stdc++.h>

using namespace std;



int dijkstra(map<int, map<int, int>> &nodes, int start, int end, int x)
{
    vector<int> dist(1001, 1e9);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        auto [cost, here] = pq.top();
        pq.pop();

        if (dist[here] < cost) continue;

        for (const auto& [there, weight] : nodes[here])
        {
            int nextCost = cost + (weight > x);
            if (dist[there] > nextCost)
            {
                dist[there] = nextCost;
                pq.push({nextCost, there});
            }
        }
    }

    return dist[end];
}

int binary_search(map<int, map<int, int>> nodes, int n, int k)
{
    int left = 0, right = 1000000, result  = -1;
    
    while(left <= right)
    {
        int mid = (left + right) / 2; // 최대 가격의 제한값
        int cost = dijkstra(nodes, 1, n, mid);

        if (cost <= k) 
        {
            result = mid;
            right = mid - 1;
        } 
        else 
        {
            left = mid + 1;
        }
    }
    
    return result;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, p, k;
    
    cin >> n >> p >> k;
    
    map<int, map<int, int>> nodes;
    
    for(int i = 0; i < p; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        nodes[a][b] = w;
        nodes[b][a] = w;
    }
    
    int result = binary_search(nodes, n, k);
    
    cout << result << endl;
    
}