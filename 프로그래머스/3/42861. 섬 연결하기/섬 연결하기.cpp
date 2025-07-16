#include <bits/stdc++.h>

using namespace std;

int getParent(int a, int parent[])
{
    if(a == parent[a])
        return a;
    return parent[a] = getParent(parent[a], parent);
    
}

void UnionFind(int a, int b, int parent[]){
    a = getParent(a, parent);
    b = getParent(b, parent);
    
    if(a < b)
        parent[b] = a;
    else
        parent[a] = b;
}

bool compare(vector<int> a, vector<int> b){
    return a[2] < b[2];
}

int solution(int n, vector<vector<int>> costs) 
{
    int answer = 0;
    int parent[n];
    
    //부모 자신으로 초기화
    for(int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    
    sort(costs.begin(), costs.end(), compare);
    for(vector<int> cost : costs)
    {
        int a = getParent(cost[0], parent);
        int b = getParent(cost[1], parent);
        if(parent[a] != parent[b]){
            answer += cost[2];
            UnionFind(a, b, parent);
        }
    }
    
    return answer;
}