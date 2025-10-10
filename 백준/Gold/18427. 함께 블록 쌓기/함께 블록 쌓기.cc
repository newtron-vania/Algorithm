#include <bits/stdc++.h>

using namespace std;

const int MOD = 10007;

int main()
{
    int n, m, h;
    scanf("%d %d %d", &n, &m, &h);

    vector<vector<int>> student(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int x;
        while (true)
        {
            int result = scanf("%d", &x);
            if (result == EOF || x == 0) break;
            student[i].push_back(x);
            if (getchar() == '\n') break;
        }
    }

    int dp[1001][1001] = {0};
    dp[0][0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= h; j++)
        {
            dp[i][j] = dp[i - 1][j] % MOD;
            for (int block : student[i])
            {
                if (j - block >= 0)
                {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - block]) % MOD;
                }
            }
        }
    }

    printf("%d\n", dp[n][h] % MOD);
    return 0;
}
