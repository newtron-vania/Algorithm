#include <cstdio>

using namespace std;

int dp[41];
int vip[41];

int main()
{
    int N, M;
    scanf("%d", &N);
    scanf("%d", &M);

    for (int i = 0; i < M; i++)
    {
        scanf("%d", &vip[i]);
    }

    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= N; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    int result = 1;
    int last = 0;

    for (int i = 0; i < M; i++)
    {
        int len = vip[i] - last - 1;
        result *= dp[len];
        last = vip[i];
    }

    result *= dp[N - last];

    printf("%d\n", result);
    return 0;
}
