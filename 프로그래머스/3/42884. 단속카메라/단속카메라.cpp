#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(vector<int>& a, vector<int>& b) 
{
    return a[0] < b[0];
}

int solution(vector<vector<int>> routes) {
    // 차량의 경로를 진입 지점을 기준으로 정렬
    sort(routes.begin(), routes.end(), comp);

    int answer = 1;
    int cameraPos = routes[0][1]; // 초기 카메라 위치 설정

    for (int i = 1; i < routes.size(); ++i) {
        // 현재 차량의 진출 지점이 현재 카메라 위치보다 작으면 카메라를 옮김
        if (routes[i][0] <= cameraPos) {
            cameraPos = min(cameraPos, routes[i][1]);
        } else {
            // 현재 차량의 진입 지점이 현재 카메라 위치보다 크면 새로운 카메라 설치
            cameraPos = routes[i][1];
            answer++;
        }
    }

    // 마지막 차량은 설치된 카메라와 겹칠 수 있으므로 추가로 설치 여부 확인
    if (cameraPos < routes.back()[0]) {
        answer++;
    }

    return answer;
}