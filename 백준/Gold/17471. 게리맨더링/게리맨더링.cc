#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;

vector<int> counts;
vector<vector<int>> graph;
int n, answer = INF;

// BFS를 이용해 하나의 조합에서 연결된 노드와 그들의 값을 계산
pair<int, int> bfs(const vector<int>& combin)
{
    int x = combin[0];
    set<int> visited;
    visited.insert(x);
    int result = counts[x];
    queue<int> q;
    q.push(x);
    
    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        for (int next : graph[current])
        {
            if (find(combin.begin(), combin.end(), next) != combin.end() && visited.find(next) == visited.end())
            {
                result += counts[next];
                visited.insert(next);
                q.push(next);
            }
        }
    }
    return {result, (int)visited.size()};
}

// DFS로 특정 크기의 조합을 구함
void dfs(int start, int depth, vector<int>& combin)
{
    if (combin.size() == depth)
    {
        // combin을 선택했을 때 연결된 부분을 BFS로 확인
        pair<int, int> c1 = bfs(combin);

        // 나머지 노드를 구함
        vector<int> rest;
        for (int i = 1; i <= n; i++)
        {
            if (find(combin.begin(), combin.end(), i) == combin.end())
            {
                rest.push_back(i);
            }
        }
        
        // 나머지 노드들도 BFS로 확인
        pair<int, int> c2 = bfs(rest);

        // 전체 노드를 다 방문했는지 확인
        if (c1.second + c2.second == n)
        {
            answer = min(answer, abs(c1.first - c2.first));
        }
        return;
    }

    for (int i = start; i <= n; i++)
    {
        combin.push_back(i);
        dfs(i + 1, depth, combin);
        combin.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    counts.resize(n + 1);
    graph.resize(n + 1);
    
    for (int i = 1; i <= n; i++)
    {
        cin >> counts[i];
    }
    
    for (int i = 1; i <= n; i++)
    {
        int m;
        cin >> m;
        for (int j = 0; j < m; j++)
        {
            int neighbor;
            cin >> neighbor;
            graph[i].push_back(neighbor);
        }
    }
    
    // 전체 노드를 절반으로 나누어 조합을 구함
    for (int i = 1; i <= n / 2; i++)
    {
        vector<int> combin;
        dfs(1, i, combin);
    }
    
    cout << (answer == INF ? -1 : answer) << endl;
    
    return 0;
}
