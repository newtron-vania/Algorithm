#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    vector<int> inDegree(n + 1, 0);
    
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        inDegree[b]++;
    }

    queue<int> queue;
    for (int i = 1; i <= n; i++)
    {
        if (inDegree[i] == 0)
        {
            queue.push(i);
        }
    }

    vector<int> answer;
    while (!queue.empty())
    {
        int x = queue.front();
        queue.pop();
        answer.push_back(x);
        
        for (int next : graph[x])
        {
            inDegree[next]--;
            if (inDegree[next] == 0)
            {
                queue.push(next);
            }
        }
    }

    for (int num : answer)
    {
        cout << num << " ";
    }
    cout << "\n";

    return 0;
}
