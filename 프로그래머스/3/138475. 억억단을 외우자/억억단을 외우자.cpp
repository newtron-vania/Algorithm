#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> solution(int e, vector<int> starts) {
    int minS = starts[0];
    // 시간을 줄이기 위해 S중 최솟값을 찾아 넣음
    for(auto it : starts) minS = min(minS,it);
    
    vector<int> dp(e+1),arr(e+1); // arr, dp 배열 만듬
    for(int i = 1; i <= e; i++) dp[i] = i;

    
    // arr에 각 번호의 개수 채워넣음
    for(int i = 2; i <= e; i++)
        for(int j = 1; j <= e; j++) {
            if(i*j > e) break;
            arr[i*j]++;
        }
    
    // e-1개부터 역순으로 탐색
    for(int i = e-1; i >= minS; i--){
        if(arr[i] >= arr[dp[i+1]]) dp[i] = i;
        else dp[i] = dp[i+1];
    }
    
    vector<int> answer;
    for(auto start : starts) 
        answer.push_back(dp[start]);
    return answer;
}