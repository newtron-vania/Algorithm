#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    bool dp[n + 5] = {false, };
    dp[1] = false;
    dp[2] = true;
    dp[3] = false;
    dp[4] = true;

    for (int i = 5; i <= n; i++)
    {
        if (!dp[i - 1] || !dp[i - 3] || !dp[i - 4])
        {
            dp[i] = true;
        }
        else
        {
            dp[i] = false;
        }
    }

    cout << (dp[n] ? "SK" : "CY") << '\n';
    return 0;
}
