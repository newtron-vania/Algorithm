#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> nodes; // 간선 정보로 nodes 생성
vector<bool> visited;
vector<int> indegree; // 진입 간선
vector<long long> long_a; // 연산 수행 위한 long 배열
long long result;

void topology() 
{
    queue<int> q;
    for (int i = 0; i < indegree.size(); ++i)
    {
        if (indegree[i] == 1) q.push(i);
    }

    while (!q.empty()) 
    {
        int current = q.front();
        q.pop();
        visited[current] = true;

        for (int next : nodes[current])
        {
            if (!visited[next])
            {
                indegree[next]--;
                long_a[next] += long_a[current]; // +1, -1 해주었다고 생각하여 합친 값을 저장    
                result += abs(long_a[current]); // 현재 노드에서 이동한 값 만큼 result에 더해줌 
                long_a[current] = 0; // 현재 노드의 모든 가중치 값을 부모로 이동.
                if (indegree[next] == 1) q.push(next);
            }
        }
    }
}

long long solution(vector<int> a, vector<vector<int>> edges) 
{
    long_a = vector<long long>(a.begin(), a.end());
    nodes = vector<vector<int>>(a.size());
    long long sum = 0;
    for (int i = 0; i < a.size(); ++i) 
    {
        sum += a[i];
    }
    if (sum != 0) return -1;

    indegree = vector<int>(a.size(), 0);
    for (const auto& edge : edges) 
    {
        nodes[edge[0]].push_back(edge[1]);
        nodes[edge[1]].push_back(edge[0]);
        indegree[edge[0]]++;
        indegree[edge[1]]++;
    }

    visited = vector<bool>(a.size(), false);
    result = 0;
    topology(); // 위상정렬 알고리즘 활용하여 리프노드에서 루트까지 가중치 이동횟수 구함
    return result;
}
