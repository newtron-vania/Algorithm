#include <bits/stdc++.h>

using namespace std;

int N;
int price[16][16];
int dp[16][1<<15][10]; // cur, mask, last_price(0~9)

int dfs(int cur, int mask, int last)
{
    int &ret = dp[cur][mask][last];
    if (ret != -1) return ret;
    ret = 1;

    for (int next = 0; next < N; next++)
    {
        if (mask & (1 << next)) continue;
        int p = price[cur][next];
        if (p >= last)
        {
            ret = max(ret, 1 + dfs(next, mask | (1<<next), p));
        }
    }
    return ret;
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        char s[20];
        scanf("%s", s);
        for (int j = 0; j < N; j++)
        {
            price[i][j] = s[j] - '0';
        }
    }

    memset(dp, -1, sizeof(dp));

    int ans = dfs(0, 1<<0, 0);
    printf("%d\n", ans);
    return 0;
}
