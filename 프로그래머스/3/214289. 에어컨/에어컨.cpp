#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

vector<vector<int>> dp;
const int MAX = 1000001;
const int MAX_TEMP = 40, MIN_TEMP = -10, RANGE = MAX_TEMP - MIN_TEMP;

int solution(int temperature, int t1, int t2, int a, int b, vector<int> onboard) 
{
    if (t1 <= temperature && temperature <= t2) return 0;

    temperature -= MIN_TEMP;
    t1 -= MIN_TEMP;
    t2 -= MIN_TEMP;

    dp = vector<vector<int>>(onboard.size(), vector<int>(RANGE + 1, MAX));
    dp[0][temperature] = 0;

    for (int i = 0; i < onboard.size() - 1; i++) 
    {
        for (int j = 0; j <= RANGE; j++) 
        {
            if (onboard[i] == 1 && (j < t1 || j > t2)) continue;
            
            int nextTemp = j;
            
            if (j < temperature && j < RANGE) 
                nextTemp = j + 1;
            else if (j > temperature && j > 0) 
                nextTemp = j - 1;
            
            dp[i + 1][nextTemp] = min(dp[i][j], dp[i + 1][nextTemp]);

            if (j > 0) dp[i + 1][j - 1] = 
                min(dp[i][j] + a, dp[i + 1][j - 1]);
            if (j < RANGE) dp[i + 1][j + 1] = 
                min(dp[i][j] + a, dp[i + 1][j + 1]);
            
            dp[i + 1][j] = min(dp[i][j] + b, dp[i + 1][j]);
        }
    }

    int answer = MAX;
    for (int j = 0; j <= RANGE; j++) 
    {
        if (onboard[onboard.size() - 1] == 1 && (j < t1 || j > t2)) continue;
        
        answer = min(dp[onboard.size() - 1][j], answer);
    }

    return answer;
}