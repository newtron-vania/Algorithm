#include <vector>

using namespace std;

int MOD = 20170805;
int dp[510][510][2];

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    int answer = 0;

    for(int x = 0; x < m; x++){
        for(int y = 0; y<n; y++){
            if(x == 0 && y == 0){
                dp[x][y][0] = 1;
                dp[x][y][1] = 0;
                continue;
            }
            //좌측에서, 위쪽에서 오는 경우의 수 따로 저장
            if(city_map[x][y] == 1){
                dp[x][y][0] = dp[x][y][1] = 0;
                continue;
            }
                
            
            //좌측에서 방향전환 없이 오는 경우 (= dp[x-1][y][0])
            dp[x][y][0] = x > 0 ? dp[x-1][y][0] % MOD : 0;
            //좌측에 1이 있지 않은 경우엔 방향전환하여 오는 경우도 더한다. (= dp[x-1][y][1])
            dp[x][y][0] += (x > 0 && city_map[x-1][y] != 2) ? dp[x-1][y][1] % MOD : 0;
            //위쪽에서 방향전환 없이 오는 경우 (=dp[x][y-1][1])
            dp[x][y][1] = y > 0 ? dp[x][y-1][1] % MOD : 0;
            //위쪽에 1이 있지 않은 경우엔 방향전환하여 오는 경우도 더한다. (= dp[x][y-1][0])
            dp[x][y][1] += (y > 0 && city_map[x][y-1] != 2) ? dp[x][y-1][0] % MOD : 0;
        }
    }
    answer = (dp[m-1][n-1][0]+ dp[m-1][n-1][1]) % MOD;
    return answer;
}