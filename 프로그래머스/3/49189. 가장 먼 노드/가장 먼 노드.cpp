#include <string>
#include <vector>
#include <queue>

using namespace std;



int solution(int n, vector<vector<int>> edge) {
    int answer = -1;
    
    vector<vector<int>> graph(edge.size()+1, vector<int>());
    vector<bool> visited(edge.size()+1, false);
    for(vector<int> e : edge)
    {
        int from = e[0];
        int to = e[1];
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    
    queue<vector<int>> q;
    q.push({1});
    visited[1] = true;
    
    while(!q.empty())
    {
        vector<int> froms = q.front();
        q.pop();
        
        vector<int> tos;
        for(int from : froms)
        {
            for(int next : graph[from])
            {
                if(!visited[next])
                {
                    visited[next] = true;
                    tos.push_back(next);
                }
            }
        }
        if(tos.size() > 0)
        {
            answer = tos.size();
            q.push(tos);
        }
    }
    
    return answer;
}