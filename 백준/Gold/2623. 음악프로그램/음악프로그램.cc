#include <bits/stdc++.h>

using namespace std;

void topology_sort(int n, int m, vector<vector<int>>& graph, vector<int>& indegree)
{
    vector<int> result;
    queue<int> q;

    for (int i = 1; i <= n; ++i)
    {
        if (indegree[i] == 0) 
        {
            q.push(i);
        }
    }

    while (!q.empty()) 
    {
        int now = q.front();
        q.pop();
        result.push_back(now);

        for (int node : graph[now])
        {
            indegree[node]--;
            if (indegree[node] == 0)
            {
                q.push(node);
            }
        }
    }

    if (result.size() != n) 
    {
        cout << 0 << endl;
    } else {
        for (int i : result)
        {
            cout << i << endl;
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);

    vector<int> indegree(n + 1, 0);

    for (int i = 0; i < m; ++i) 
    {
        int k;
        cin >> k;
        vector<int> tmp_list(k);
        for (int j = 0; j < k; ++j)
        {
            cin >> tmp_list[j];
        }
        for (int j = 1; j < k; ++j) 
        {
            int start = tmp_list[j - 1];
            int finish = tmp_list[j];
            graph[start].push_back(finish);
            indegree[finish]++;
        }
    }

    topology_sort(n, m, graph, indegree);

    return 0;
}
