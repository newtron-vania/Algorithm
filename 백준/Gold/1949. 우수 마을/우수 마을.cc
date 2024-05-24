#include <bits/stdc++.h>

using namespace std;

int dp[10001][2];
int civilNum[10001];
bool visited[10001];


void dfs(int now, vector<vector<int>>& nodes)
{
    visited[now] = true;
    
    dp[now][0] = 0;
    dp[now][1] = civilNum[now];
    
    for(int next : nodes[now])
    {
        if(visited[next]) continue;
        
        dfs(next, nodes);
        
        dp[now][0] += max(dp[next][1], dp[next][0]);
        dp[now][1] += dp[next][0];
    }
}

int main()
{
    int N;
    cin >> N;
    
    vector<vector<int>> nodes(N + 1, vector<int>());
    
    for(int i = 1; i <= N; i++)
    {
        int a;
        cin >> a;
        civilNum[i] = a;
    }
    
    for(int i = 0; i < N-1; i++)
    {
        int a, b;
        cin >> a >> b;
        nodes[a].push_back(b);
        nodes[b].push_back(a);
    }
    
    dfs(1, nodes);
    cout << max(dp[1][0], dp[1][1]) << endl;
    
    return 0;
}