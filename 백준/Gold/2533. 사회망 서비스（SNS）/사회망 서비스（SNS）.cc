#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX = 1000001;
vector<int> tree[MAX];
 
// now가 루트일 때의 서브트리에서 얼리아답터의 최소 수
int dp[MAX][2];
bool visited[MAX];
void dfs(int now)
{
    visited[now] = true;
    dp[now][0] = 0;
    dp[now][1] = 1;
    
    for(int i = 0; i < tree[now].size(); i++)
    {
        int next = tree[now][i];
        if(visited[next]) continue;
        
        dfs(next);
        
        dp[now][0] += dp[next][1];
        dp[now][1] += min(dp[next][0], dp[next][1]);
    }
}
 
int main()
{
    ios_base::sync_with_stdio(NULL); 
    cin.tie(NULL);  cout.tie(NULL);
    
    int u, v, N;
    cin >> N;
    for(int i = 0; i < N-1; i++)
    {
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs(1);
    cout << min(dp[1][0], dp[1][1]);
    return 0;
}