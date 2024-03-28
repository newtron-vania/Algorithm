#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

const int LIMIT_VALUE = 100'000;

int main()
{
    int n;
    cin >> n;
    
    vector<int> dp(LIMIT_VALUE+1, LIMIT_VALUE);
    
    dp[2] = 1;
    dp[4] = 2;
    dp[5] = 1;
    
    for(int i = 6; i <= n; i++)
    {
        dp[i] = min(dp[i-2] + 1, dp[i-5] + 1);
    }
    
    cout << (dp[n] < LIMIT_VALUE ? dp[n] : -1) << endl;
    
    return 0;
}