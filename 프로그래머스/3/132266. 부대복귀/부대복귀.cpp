#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

// n : 노드
// roads : 간선
// sources : 시작 노드
// destination : 도착 노드


void dijkstra(int start, vector<int> &visited, vector<vector<int>> &nodes){
    queue<int> queue;
    queue.push(start);
    visited[start] = 0;
    while(!queue.empty())
    {
        int node = queue.front();
        queue.pop();
        for(int next : nodes[node])
        {
            if(visited[next] > 0)
                continue;
            if(visited[next] == -1)
                visited[next] = 0;
            visited[next] = visited[node] + 1;
            queue.push(next);
        }
    }
    visited[start] = 0;
    return;
}

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) 
{
    vector<int> answer;
    vector<vector<int>> nodes(n+1, vector<int>());
    vector<int> visited(n+1, -1);
    for(vector<int> road : roads)
    {
        nodes[road[0]].push_back(road[1]);
        nodes[road[1]].push_back(road[0]);
    }
    
    dijkstra(destination, visited, nodes);
    
    for(int source : sources)
    {
        answer.push_back(visited[source]);
    }
    
    return answer;
}