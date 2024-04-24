#include <bits/stdc++.h>

using namespace std;

const int inf = 100001;
stack<pair<int, int>> r;
set<int> st[inf];
stack<int> ans;
int n, q, p[inf], e[inf];

int find(int x) 
{
    return p[x] == x ? x : p[x] = find(p[x]);
}

void merge(int par, int son) 
{
    par = find(par), son = find(son);
    if (par == son) return;
    if (st[son].size() < st[par].size())
    {
        p[son] = par;
        for (int c : st[son]) st[par].insert(c);
        st[son].clear();
    } 
    else 
    {
        p[par] = son;
        for (int c : st[par]) st[son].insert(c);
        st[par].clear();
    }
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    e[1] = p[1] = 1;
    
    for (int i = 2; i <= n; i++) 
    {
        cin >> e[i];
        p[i] = i;
    }
    
    
    for(int i = 1; i <= n; i++)
    {
        int color;
        cin >> color;
        st[i].insert(color);
    }
    
    for (int i = 0; i < q + n - 1; i++)
    {
        int a, b; 
        cin >> a >> b;
        r.push({a, b});
    }
    
    while (!r.empty()) 
    {
        auto k = r.top();
        r.pop();
        // 색 개수 구하기
        if (k.first == 2)
        {
            int par = find(k.second);
            ans.push(st[par].size());
        }
        // 간선 연결 및 색 개수 구하기
        else
        {
            int par = e[k.second];
            merge(par, k.second);
        }  
    }
    
    while (!ans.empty()) 
    {
        cout << ans.top() << '\n';
        ans.pop();
    }
    return 0;
}