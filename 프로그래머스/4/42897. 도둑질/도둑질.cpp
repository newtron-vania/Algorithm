#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> money) {
    int answer = 0;
    int size = money.size();
    int* dp = new int[size];
    dp[0] = money[0];
    dp[1] = money[0];
    
    for(int i = 2; i < size - 1; i++)
    {
        dp[i] = max(dp[i-2] + money[i], dp[i-1]);
    }
    
    answer = dp[size-2];
    
    dp[0] = 0;
    dp[1] = money[1];
    
    for(int i = 2; i < size; i++)
    {
        dp[i] = max(dp[i-2] + money[i], dp[i-1]);
    }
    
    answer = max(answer,dp[size-1]);
    
    delete[] dp;
    return answer;
}