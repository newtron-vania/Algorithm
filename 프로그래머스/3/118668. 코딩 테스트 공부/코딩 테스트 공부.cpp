#include <bits/stdc++.h>

using namespace std;

const int INF = 10001;

int solution(int alp, int cop, vector<vector<int>> problems)
{
    int dp[151][151]; // dp[i][j] : 알고력 i, 코딩력 j를 달성하기 위한 최소 시간
    fill(&dp[0][0], &dp[150][151], INF); // 모든 값을 INF로 초기화
    
    int goal_alp = 0, goal_cop = 0;
    
    for(auto problem : problems)
    {
        goal_alp = max(goal_alp, problem[0]);
        goal_cop = max(goal_cop, problem[1]);
    }
    
    int min_alp = min(alp, goal_alp);
    int min_cop = min(cop, goal_cop);
    
    dp[min_alp][min_cop] = 0;
    
    for(int i = min_alp; i <= goal_alp; i++)
    {
        for(int j = min_cop; j <= goal_cop; j++)
        {
            if(i < goal_alp)
            {
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
            }
            
            if(j < goal_cop)
            {
                dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + 1);
            }
            
            for(auto problem : problems)
            {
                if(problem[0] <= i && problem[1] <= j)
                {
                    int next_alp = min(goal_alp, i + problem[2]);
                    int next_cop = min(goal_cop, j + problem[3]);
                    dp[next_alp][next_cop] = min(dp[next_alp][next_cop], dp[i][j] + problem[4]);
                }
            }
        }
    }

    return dp[goal_alp][goal_cop]; // 목표 알고력, 코딩력을 달성하는 데 필요한 최소 시간 반환
}
