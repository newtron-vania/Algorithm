#include <string>
#include <vector>

using namespace std;


//카탈란 수 점화식 적용
int solution(int n) {
    int answer = 0;
    int* dp = new int[n+1];
    for(int i = 0; i <= n ; i++)
    {
        dp[i] = 0;
    }
    dp[0] = dp[1] = 1;
    
    for(int i = 2; i <= n; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            dp[i] += dp[j-1] * dp[i-j];
        }
    }
    
    answer = dp[n];
    delete[] dp;
    return answer;
}