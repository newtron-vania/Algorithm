#include <bits/stdc++.h>

using namespace std;

const int DIVIDE = 15746;

int main()
{
    int n;
    cin >> n;

    vector<int> dp(n + 1 < 3 ? 3 : n + 1, 0);
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2]) % DIVIDE;
    }

    cout << dp[n];
    return 0;
}
