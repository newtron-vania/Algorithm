#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000001;

int dp[MAX];
int from[MAX];


int main()
{
    int n;
    cin >> n;

    dp[1] = 0;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + 1;
        from[i] = i - 1;

        if (i % 2 == 0 && dp[i / 2] + 1 < dp[i])
        {
            dp[i] = dp[i / 2] + 1;
            from[i] = i / 2;
        }

        if (i % 3 == 0 && dp[i / 3] + 1 < dp[i])
        {
            dp[i] = dp[i / 3] + 1;
            from[i] = i / 3;
        }
    }

    cout << dp[n] << '\n';

    int cur = n;
    while (cur != 0)
    {
        cout << cur << ' ';
        cur = from[cur];
    }

    return 0;
}
