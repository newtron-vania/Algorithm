#include <string>
#include <vector>
#include <algorithm>
#include <limits>
#include <iostream>

using namespace std;

const long long INF = numeric_limits<long long>::max();

long long dp[201][201];
int solution(vector<vector<int>> matrix_sizes) {
    int answer = 0;
    int matrix_size = matrix_sizes.size();
    
    fill(dp[0], dp[200], INF);
    
    for(int i = 0 ; i < matrix_size; i++)
    {
        dp[i][i] = 0;
    }
    
    for(int n = 1; n < matrix_size; n++)
    {
        for(int i = 0; i < matrix_size - n; i++)
        {
            int j = i + n;
            
            for(int k = i; k < j; k++)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + (matrix_sizes[i][0] * matrix_sizes[k+1][0] * matrix_sizes[j][1]));
            }
        }
    }
    
    answer = dp[0][matrix_size - 1];
    return answer;
}