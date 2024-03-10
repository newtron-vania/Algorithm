#include <string>
#include <vector>

using namespace std;

const int MAX = 1234567;

long long solution(int n) {
    if(n == 1)
        return 1;
    else if(n==2)
        return 2;
    
    int answer = 0;
    
    int *dp = new int[n+1];
    dp[1] = 1;
    dp[2] = 2;
    
    for(int i = 3; i <= n; i++)
    {
        dp[i] = (dp[i-1] + dp[i-2]) % MAX;
    }
    
    answer = dp[n];
    delete[] dp;
    
    return answer;
}