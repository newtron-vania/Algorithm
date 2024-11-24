#include <bits/stdc++.h>

using namespace std;

const int MAX_VALUE = 1'000'000'007;

long long int dp[1'000'001][2];

int main()
{
    int n;
    cin >> n;
    
    dp[0][0] = 0;
    dp[1][0] = 2;
    dp[2][0] = 7;
    dp[2][1] = 1;
    
    for(int i = 3; i <= n; i++)
    {
        dp[i][1] = (dp[i-1][1] + dp[i-3][0]) % MAX_VALUE;
        dp[i][0] = (2 * dp[i-1][0] + 3 * dp[i-2][0] + 2 * dp[i][1]) % MAX_VALUE;
    }
    
    cout << dp[n][0] % MAX_VALUE;
}