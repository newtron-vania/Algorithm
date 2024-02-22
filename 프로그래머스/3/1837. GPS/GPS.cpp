#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log) {
    // 각 거점 간의 연결 상태를 나타내는 그래프 생성
    vector<vector<bool>> graph(n, vector<bool>(n, false));
    for (const auto& edge : edge_list) 
    {
        graph[edge[0] - 1][edge[1] - 1] = true;
        graph[edge[1] - 1][edge[0] - 1] = true;
    }

    // 동적 프로그래밍을 위한 테이블 초기화
    vector<vector<int>> dp(k, vector<int>(n, INT_MAX / 2));
    dp[0][gps_log[0] - 1] = 0;

    // 각 단계별로 모든 거점에 대해 최소 수정 횟수 계산
    for (int i = 1; i < k; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            // 이전 단계에서 직접 오는 경우
            dp[i][j] = min(dp[i][j], dp[i - 1][j] + (gps_log[i] - 1 != j));
            
            // 인접한 거점을 통해 오는 경우
            for (int adj = 0; adj < n; adj++) 
            {
                if (graph[j][adj]) 
                {
                    dp[i][j] = min(dp[i][j], dp[i - 1][adj] + (gps_log[i] - 1 != j));
                }
            }
        }
    }

    // 최종 단계에서의 최소 수정 횟수
    int answer = dp[k - 1][gps_log.back() - 1];
    return answer >= INT_MAX / 2 ? -1 : answer;
}