#include <string>
#include <vector>
#define INF 10001

using namespace std;

int solution(int alp, int cop, vector<vector<int>> problems) {
    int dp[151][151]; // dp[alp][cop] := 최소 공부 시간
    fill(&dp[0][0], &dp[150][151], INF); // 모든 배열 요소를 INF로 초기화
    
    int goal_alp = 0, goal_cop = 0; // 목표 알고력과 코딩력
    for(auto p : problems) { // 각 문제를 순회하며 목표 알고력과 코딩력을 결정
        goal_alp = max(goal_alp, p[0]);
        goal_cop = max(goal_cop, p[1]);
    }
    alp = min(alp, goal_alp); // 시작 알고력을 목표치와 비교하여 조정
    cop = min(cop, goal_cop); // 시작 코딩력을 목표치와 비교하여 조정

    dp[alp][cop] = 0; // 시작점의 최소 시간은 0
    for(int i = alp; i <= goal_alp; i++) {
        for(int j = cop; j <= goal_cop; j++) {
            // 알고력과 코딩력을 1씩 증가시키는 경우
            if (i < goal_alp) dp[i+1][j] = min(dp[i+1][j], dp[i][j]+1);
            if (j < goal_cop) dp[i][j+1] = min(dp[i][j+1], dp[i][j]+1);

            // 문제를 해결하여 알고력과 코딩력을 증가시키는 경우
            for(auto p : problems) {
                if ((p[0] <= i) && (p[1] <= j)) {
                    int next_alp = min(i + p[2], goal_alp);
                    int next_cop = min(j + p[3], goal_cop);
                    dp[next_alp][next_cop] = min(dp[next_alp][next_cop], dp[i][j] + p[4]);
                }
            }
        }
    }
    
    return dp[goal_alp][goal_cop]; // 목표치에 도달하기 위한 최소 시간 반환
}
