#include<bits/stdc++.h>
using namespace std;

const int MAX_DP_VALUE = 1000;
const int MAX_COUNTS_VALUE = 100;
int dp[MAX_DP_VALUE + 1];
int CostClient[MAX_COUNTS_VALUE + 1];

int main()
{
    int C, N;
    
    cin >> C >> N;
    
    fill_n(dp, MAX_DP_VALUE + 1, 987654321);
    dp[0] = 0;
    fill_n(CostClient, MAX_COUNTS_VALUE + 1, 0);
    
    int c, n;
    while(N--> 0)
    {
        cin >> c >> n;
        CostClient[c] = max(CostClient[c], n);
    }
    
    for(int i = 1; i <= MAX_COUNTS_VALUE; i++)
    {
        if(CostClient[i] <= 0) continue;
        for(int j = 1; j <= C; j++)
        {
            // 현재 비용 = min(현재 비용, (현재 관객수  - 현재 비용의 관객수)의 최소 비용 + 추가 비용)
            // {5, 1}과 {10, 3000}이 있을 경우 8의 관객을 모을 때, 3의 관객을 모을 땐 5*3보다 10의 비용을 써서 처리하는 게 더 낫다.
            dp[j] = min(dp[j], dp[( j >= CostClient[i] ? j - CostClient[i] : 0)] + i);
        }
    }
    
    cout << dp[C] << endl;
    
}
