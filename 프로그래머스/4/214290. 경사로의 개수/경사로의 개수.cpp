#include <iostream>
#include <vector>

using namespace std;

// 두 행렬을 곱하는 함수 선언
vector<vector<long long>> mulMatrix(const vector<vector<long long>>& a, const vector<vector<long long>>& b, int n);

// 상수 선언
const int MOD = 1000000007; // 나머지 연산을 위한 모듈러 값
const int dx[] = {1, 0, -1, 0}; // x축 이동에 대한 방향 벡터
const int dy[] = {0, 1, 0, -1}; // y축 이동에 대한 방향 벡터

// 주어진 조건에 따라 가능한 경로 수를 계산하는 함수
int solution(vector<vector<int>> grid, vector<int> d, int k) {
    int n = grid.size(); // 그리드의 행 개수
    int m = grid[0].size(); // 그리드의 열 개수
    int dl = d.size(); // d 배열의 크기

    // 다이나믹 프로그래밍을 위한 3차원 벡터 초기화
    vector<vector<vector<long long>>> dp(dl + 1, vector<vector<long long>>(n * m, vector<long long>(n * m, 0)));
    
    // 기저 상태 초기화
    for (int i = 0; i < n * m; i++) 
    {
        dp[0][i][i] = 1;
    }

    // 다이나믹 프로그래밍으로 각 상태 계산
    for (int l = 1; l <= dl; l++)
    {
        for (int i = 0; i < n * m; i++) 
        {
            int x = i % m; // 현재 위치의 x 좌표
            int y = i / m; // 현재 위치의 y 좌표

            for (int dir = 0; dir < 4; dir++) // 4가지 방향에 대해 반복
            {
                int nx = x + dx[dir]; // 새로운 x 좌표
                int ny = y + dy[dir]; // 새로운 y 좌표

                // 그리드 경계 및 조건 검사
                if (nx < 0 || nx >= m || ny < 0 || ny >= n || grid[ny][nx] - grid[y][x] != d[l - 1]) {
                    continue;
                }

                // 다음 상태로의 전이
                for (int j = 0; j < n * m; j++) {
                    dp[l][j][ny * m + nx] += dp[l - 1][j][i] % MOD;
                    dp[l][j][ny * m + nx] %= MOD;
                }
            }
        }
    }

    // 이진 지수 승을 위한 카운트 계산
    int count = 0;
    while ((1 << count) < k) 
    {
        count++;
    }

    // 지수 승 계산을 위한 에지 파워 벡터 초기화 및 계산
    vector<vector<vector<long long>>> edgePower(count + 1, vector<vector<long long>>(n * m, vector<long long>(n * m, 0)));
    edgePower[0] = dp[dl];
    for (int c = 1; c <= count; c++) 
    {
        edgePower[c] = mulMatrix(edgePower[c - 1], edgePower[c - 1], n * m);
    }

    // 결과를 저장할 행렬 초기화
    vector<vector<long long>> mat(n * m, vector<long long>(n * m, 0));
    for (int i = 0; i < n * m; i++) 
    {
        mat[i][i] = 1;
    }

    // k번 이동에 대한 최종 결과 계산
    int kNum = k;
    while (kNum > 0) 
    {
        if (kNum >= (1 << count)) 
        {
            mat = mulMatrix(mat, edgePower[count], n * m);
            kNum -= (1 << count);
        }
        count--;
    }

    // 결과값 계산 및 반환
    long long answer = 0;
    for (int i = 0; i < n * m; i++) 
    {
        for (int j = 0; j < n * m; j++) 
        {
            answer += mat[i][j];
            answer %= MOD;
        }
    }

    return static_cast<int>(answer);
}

// 두 행렬을 곱하는 함수 구현
vector<vector<long long>> mulMatrix(const vector<vector<long long>>& a, const vector<vector<long long>>& b, int n) 
{
    vector<vector<long long>> result(n, vector<long long>(n, 0));
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            for (int k = 0; k < n; k++) 
            {
                result[i][j] = (result[i][j] + ((a[i][k] * b[k][j]) % MOD)) % MOD;
            }
        }
    }
    return result;
}