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
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (computers[i][j] == 1 && (parent[i] != parent[j]))
                Union(i, j);
        }
    }
    
    for (int i = 0; i < parent.size(); i++) parent[i] = Find(i);
    
    set<int> parentSet(parent.begin(), parent.end());
    
    return parentSet.size();
}

int Find(int x) {
    if (parent[x] == x) {
        return x;
    }

    return parent[x] = Find(parent[x]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    if (a < b)
        parent[b] = a;
    else if (a > b)
        parent[a] = b;
}