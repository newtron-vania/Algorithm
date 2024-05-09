#define DELETED (-1)
#include <bits/stdc++.h>
using namespace std;
int N, M, S, D;
int dijkstra(vector<pair<int,int>> *adj, vector<int> *pre, int start, int dest)
{
    vector<int> dist(N, 1e9);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> PQ;
    dist[start] = 0;
    PQ.push({0, start});

    while(!PQ.empty())
    {
        auto top = PQ.top(); PQ.pop();
        int acDist = top.first, current = top.second;
        if(acDist < dist[current])
            continue;
        for(auto edge : adj[current])
        {
            int currentToNext = edge.first;
            int next = edge.second;
            if(currentToNext == DELETED)
                continue;
            if(dist[current] + currentToNext < dist[next])
            {
                dist[next] = dist[current] + currentToNext;
                pre[next].clear();
                pre[next].push_back(current);
                PQ.push({dist[next], next});
            }
            else if(dist[current] + currentToNext == dist[next])
            {
                pre[next].push_back(current);
            }
        }
    }
    return dist[dest];
}
void deleteEdges(vector<pair<int,int>> *adj, vector<int> *pre, bool *visited, int current)
{
    // 사이클 존재 시 무한 루프 방지
    if( visited[current] ) return;
    visited[current] = true;
    for(auto prev: pre[current])
    {
        for(int i=0; i<adj[prev].size(); i++)
        {
            if(adj[prev][i].second == current)
            {
                adj[prev][i].first = DELETED;
                deleteEdges(adj, pre, visited, prev);
            }
        }
    }
}
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    while(true)
    {
        cin >> N >> M;
        
        if( N == 0 && M == 0 ) break;
        
        cin >> S >> D;
        vector<pair<int,int>> adj[501];
        
        for(int i=0; i<M; i++)
        {
            int u, v, p;
            cin >> u >> v >> p;
            adj[u].push_back({p, v});
        }
        vector<int> pre[501];
        
        dijkstra(adj, pre, S, D);
        
        bool visited[501] = {false, };
        deleteEdges(adj, pre, visited, D);
        
        int ans = dijkstra(adj, pre, S, D);
        
        if(ans == 1e9) ans = -1;
        
        cout << ans << '\n';
    }

    return 0;
}