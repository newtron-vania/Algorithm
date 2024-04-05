#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

vector<vector<int>> dp; // dp 테이블 선언, 각 단계별 최소 비용을 저장
const int MAX = 1000001; // 최대 비용 상수
const int MAX_TEMP = 40, MIN_TEMP = -10, RANGE = MAX_TEMP - MIN_TEMP; // 온도 범위 상수

// 솔루션 함수
int solution(int temperature, int t1, int t2, int a, int b, vector<int> onboard) 
{
    // 초기 조건: 현재 온도가 목표 범위 내에 있는 경우, 비용은 0
    if (t1 <= temperature && temperature <= t2) return 0;

    // 온도를 0 이상의 값으로 변환
    temperature -= MIN_TEMP;
    t1 -= MIN_TEMP;
    t2 -= MIN_TEMP;

    // dp 테이블 초기화
    dp = vector<vector<int>>(onboard.size(), vector<int>(RANGE + 1, MAX));
    dp[0][temperature] = 0; // 초기 온도에 대한 비용은 0

    // 각 단계별로 최소 비용 계산
    for (int i = 0; i < onboard.size() - 1; i++) 
    {
        for (int j = 0; j <= RANGE; j++) {
            if (onboard[i] == 1 && (j < t1 || j > t2)) continue; // 온도 조절이 필요한 경우만 계산
            
            int nextTemp = j; // 다음 단계의 온도 초기화
            
            // 온도를 현재 온도에 맞추는 로직
            if (j < temperature && j < RANGE) 
                nextTemp = j + 1;
            else if (j > temperature && j > 0) 
                nextTemp = j - 1;
            
            // 다음 단계의 온도 비용 계산
            dp[i + 1][nextTemp] = min(dp[i][j], dp[i + 1][nextTemp]);

            // 온도를 조절하는 경우의 비용 계산
            if (j > 0) dp[i + 1][j - 1] = min(dp[i][j] + a, dp[i + 1][j - 1]);
            if (j < RANGE) dp[i + 1][j + 1] = min(dp[i][j] + a, dp[i + 1][j + 1]);
            
            // 현재 온도를 유지하는 경우의 비용 계산
            dp[i + 1][j] = min(dp[i][j] + b, dp[i + 1][j]);
        }
    }

    // 최종 단계에서 최소 비용 계산
    int answer = MAX;
    for (int j = 0; j <= RANGE; j++) 
    {
        if (onboard[onboard.size() - 1] == 1 && (j < t1 || j > t2)) continue; // 마지막 단계에서 온도 조절이 필요한 경우만 고려
        
        answer = min(dp[onboard.size() - 1][j], answer); // 최소 비용 갱신
    }

    return answer; // 최종 결과 반환
}