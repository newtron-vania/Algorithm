#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int F;
    cin >> F;

    int dp[500][500]; // 최대 크기는 문제 조건에 맞춰 충분히 크게 설정
    for (int i = 0; i < F; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cin >> dp[i][j];
        }
    }

    for (int i = 1; i < F; i++)
    {
        dp[i][0] += dp[i - 1][0];
        dp[i][i] += dp[i - 1][i - 1];
        for (int j = 1; j < i; j++)
        {
            dp[i][j] += max(dp[i - 1][j - 1], dp[i - 1][j]);
        }
    }

    int ans = 0;
    for (int j = 0; j < F; j++)
    {
        ans = max(ans, dp[F - 1][j]);
    }

    cout << ans << "\n";
    return 0;
}
