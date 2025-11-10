#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> dp(31, 0);

    dp[0] = 1;
    dp[2] = 3;

    for (int i = 4; i <= n; i += 2)
    {
        dp[i] = 3 * dp[i - 2];
        for (int j = i - 4; j >= 0; j -= 2)
        {
            dp[i] += 2 * dp[j];
        }
    }

    cout << dp[n];
}