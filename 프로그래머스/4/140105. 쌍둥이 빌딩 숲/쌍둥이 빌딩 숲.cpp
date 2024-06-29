#include <bits/stdc++.h>

using namespace std;

const long MAX = 1'000'000'007;
long dynamicP[101][101];

long solution(int n, int count) {
    long answer = 0;
    
    dynamicP[1][1] = 1;
    
    // 점화식 : dp[n][c] = dp[n-1][c-1] + dp[n-1][c] * 2(n-1)
    for(int col = 2; col <= n; col++)
    {
        int prevCol = col - 1;
        int maxCount = min(count, col);
        
        for(int row = 1; row <= maxCount; row++)
        {
            dynamicP[col][row] = (dynamicP[prevCol][row-1] + dynamicP[prevCol][row] * 2 * prevCol) % MAX;
        }
    }
    
    answer = dynamicP[n][count];
    return answer;
}