#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;


int Find(int a);
void Union(int a, int b);


vector<int> parent;


int solution(int n, vector<vector<int>> computers) {
    vector<int> localVec(n);
    parent = localVec;
    
    // 자기 자신 연결 확인
    for (int i = 0; i < n; i++) 
    {
        parent[i] = i;
    }

    // 연결 그래프 확인(root node를 부모 노드로 설정)
    for (int i = 0; i < n; i++) 
    {
        for (int j = i + 1; j < n; j++) 
        {
            if (computers[i][j] == 1 && (parent[i] != parent[j]))
                Union(i, j);
        }
    }
    
    // 모든 노드 root node 설정
    for (int i = 0; i < parent.size(); i++) parent[i] = Find(i);
    
    // 중복 제거
    set<int> parentSet(parent.begin(), parent.end());
    
    return parentSet.size();
}

int Find(int x) 
{
    if (parent[x] == x) 
    {
        return x;
    }

    return parent[x] = Find(parent[x]);
}

void Union(int a, int b) 
{
    a = Find(a);
    b = Find(b);
    if (a < b)
        parent[b] = a;
    else if (a > b)
        parent[a] = b;
}