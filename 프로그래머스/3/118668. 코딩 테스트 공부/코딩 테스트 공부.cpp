#include <string>
#include <vector>
#define INF 10001

using namespace std;

int solution(int alp, int cop, vector<vector<int>> problems)
{
    int dp[151][151]; // dp[i][j] : 알고력 i, 코딩력 j를 달성하기 위한 최소 시간
    fill(&dp[0][0], &dp[150][151], INF); // 모든 값을 INF로 초기화

    int goal_alp = 0, goal_cop = 0;

    // 목표 알고력과 코딩력 계산
    for (auto p : problems)
    {
        goal_alp = max(goal_alp, p[0]);
        goal_cop = max(goal_cop, p[1]);
    }

    // 초기 알고력과 코딩력이 목표보다 높으면 줄이기
    alp = min(alp, goal_alp);
    cop = min(cop, goal_cop);

    dp[alp][cop] = 0; // 시작점 설정

    // dp 갱신
    for (int i = alp; i <= goal_alp; i++)
    {
        for (int j = cop; j <= goal_cop; j++)
        {
            // 알고력 증가
            if (i < goal_alp)
            {
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
            }

            // 코딩력 증가
            if (j < goal_cop)
            {
                dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + 1);
            }

            // 문제 해결 시 능력치 증가
            for (auto p : problems)
            {
                if (p[0] <= i && p[1] <= j)
                {
                    int next_alp = min(i + p[2], goal_alp);
                    int next_cop = min(j + p[3], goal_cop);
                    dp[next_alp][next_cop] = min(dp[next_alp][next_cop], dp[i][j] + p[4]);
                }
            }
        }
    }

    return dp[goal_alp][goal_cop]; // 목표 알고력, 코딩력을 달성하는 데 필요한 최소 시간 반환
}
