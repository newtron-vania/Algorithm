#include <bits/stdc++.h>

using namespace std;

const int MAX_VALUE = 1001;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int t[MAX_VALUE], p[MAX_VALUE], dp[MAX_VALUE];

    for (int i = 0; i < n; i++)
    {
        cin >> t[i] >> p[i];
    }

    dp[n] = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        if (i + t[i] > n)
        {
            dp[i] = dp[i + 1];
        }
        else
        {
            dp[i] = max(dp[i + 1], dp[i + t[i]] + p[i]);
        }
    }

    cout << dp[0];

    return 0;
}
