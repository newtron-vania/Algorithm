#include <bits/stdc++.h>
#define ll long long

using namespace std;

int solution(vector<vector<int>> info, int n, int m)
{
    ll items = info.size();
    
    vector<vector<ll>> dp(items, vector<ll>(m));
    
    for (ll i = 0; i < items; i++)
    {
        for (ll j = 0; j < m; j++) 
        {
            
            if (i == 0)
            {
                if (info[i][1] <= j) 
                {
                    dp[i][j] = 0;
                }
                else 
                {
                    dp[i][j] = info[i][0];
                }
            } 
            else if (j - info[i][1] < 0) 
            {
                dp[i][j] = dp[i - 1][j] + info[i][0];
            }
            else
            {
                 dp[i][j] = min(dp[i - 1][j] + info[i][0], dp[i - 1][j - info[i][1]]);
            }
        }
    }
    
    ll answer;
    
    if (dp[items - 1][m - 1] < n)
    {
        answer = dp[items - 1][m - 1];
    } else 
    {
        answer = -1;
    }
    return answer;
}