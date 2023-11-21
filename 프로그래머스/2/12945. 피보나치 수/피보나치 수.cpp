#include <string>
#include <vector>

using namespace std;

const int FIB_VALUE = 1234567;

int solution(int n) {
    int answer = 0;
    
    int *dp = new int[n+1] {0,};
    
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2; i <= n; i++)
    {
        dp[i] = (dp[i-1] + dp[i-2]) % FIB_VALUE;
    }
    
    answer = dp[n];
    delete[] dp;
    return answer;
}