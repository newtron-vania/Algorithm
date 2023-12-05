#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits.h>
#include <iostream>

using namespace std;

const int MAXVALUE = INT_MAX;

int BFS(int n, vector<vector<int>>& graph, vector<bool> visited)
{
    int count = 1;
    queue<int> q;
    q.push(n);
    visited[n] = true;
    
    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
        for(int next : graph[curr])
        {
            if(!visited[next])
            {
                count++;
                visited[next] = true;
                q.push(next);
            }
        }
    }
    return count;
}

int CheckDiff(int x1, int x2, vector<vector<int>>& graph, vector<bool>& visited)
{
    return abs(BFS(x1, graph, visited) - BFS(x2, graph, visited));
}

int solution(int n, vector<vector<int>> wires) {
    int answer = MAXVALUE;
    vector<vector<int>> graph(n+1, vector<int>());
    vector<bool> visited(n+1, false);
    for(auto wire : wires)
    {
        int from = wire[0];
        int to = wire[1];
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    
    for(auto wire : wires)
    {
        int from = wire[0];
        int to = wire[1];
        
        visited[from] = true;
        visited[to] = true;
        int diff = CheckDiff(from, to, graph, visited);
        answer = min(answer, diff);
        visited[from] = false;
        visited[to] = false;
    }
    
    return answer;
}