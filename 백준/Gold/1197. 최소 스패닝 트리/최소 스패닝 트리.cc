#include <bits/stdc++.h>

using namespace std;

int parent[10001];

struct cmp {
    bool operator()(vector<int>& a, vector<int>& b) 
    {
        return a[2] > b[2]; 
    }
};

int find(int x) 
{
	if (parent[x] == x) return x;
	else return parent[x] = find(parent[x]); 
}

bool unionSets(int x, int y)
{
    x = find(x);
    y = find(y);
    if(x > y)
    {
        parent[x] = y;
        return true;
    }
    else if(x < y)
    {
        parent[y] = x;
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int answer = 0, count = 0;  
    int v, e;
    cin >> v >> e;
    
    for(int i = 1; i <= v; i++)
    {
        parent[i] = i;
    }
    
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
    
    for(int i = 0; i < e; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        
        pq.push({a, b, w});
    }
    
    while(!pq.empty())
    {
        auto next = pq.top();
        pq.pop();
        
        if(unionSets(next[0], next[1]))
        {
            answer += next[2];
            count++;
        }
        if(count >= v) break;
    }
    
    cout << answer << endl;
    
    
    
    return 0;
}