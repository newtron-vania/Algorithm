#include <vector>

using namespace std;


long long dp[100002] = { 1, 1, 3, 10, 23, 62, 170 };
long long sum[100002] = { 1, 1, 3, 11, 24, 65, 181 };

const int MOD = 1e9 + 7;

int solution(int n)
{
	for (int i = 7; i <= n; i++) 
    {
		dp[i] = dp[i - 1];
		dp[i] = (dp[i] + dp[i - 2] * 2) % MOD;
		dp[i] = (dp[i] + dp[i - 3] * 5) % MOD;
		dp[i] = (dp[i] + sum[i - 4] * 2) % MOD;
		dp[i] = (dp[i] + sum[i - 5] * 2) % MOD;
		dp[i] = (dp[i] + sum[i - 6] * 4) % MOD;

		sum[i] = (dp[i] + sum[i - 3]) % MOD;
	}

	return dp[n];
}