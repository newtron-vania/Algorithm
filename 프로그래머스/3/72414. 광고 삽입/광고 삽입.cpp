#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// 각 초에 대한 재생 횟수를 저장하는 배열
int cnt[360000];

// 문자열 형식의 시간을 초 단위의 정수로 변환하는 함수
int strtoint(string s) {
    string sec = s.substr(6, 2);
    string min = s.substr(3, 2);
    string hour = s.substr(0, 2);

    int result = stoi(sec) + stoi(min) * 60 + stoi(hour) * 3600;
    return result;
}

// 초 단위의 정수를 문자열 형식의 시간으로 변환하는 함수
string inttostr(int i) {
    int sec = i % 60;
    i /= 60;
    int min = i % 60;
    i /= 60;
    int hour = i;

    string result = "";
    if(hour < 10) result += "0";
    result += to_string(hour) + ":";
    if (min < 10) result += "0";
    result += to_string(min) + ":";
    if (sec < 10) result += "0";
    result += to_string(sec);

    return result;
}

// 광고 삽입 시간을 최적화하는 주 함수
string solution(string play_time, string adv_time, vector<string> logs) {
    int answer = 0;
    
    // 로그를 분석하여 각 초마다 시청자 수 계산
    for (int i = 0; i < logs.size(); i++) {
        int start = strtoint(logs[i].substr(0, 8));
        int end = strtoint(logs[i].substr(9));
        for (int j = start; j < end; j++) {
            cnt[j]++;
        }
    }

    int playtime = strtoint(play_time); // 동영상 총 재생 시간
    int advtime = strtoint(adv_time); // 광고 재생 시간

    queue<int> q;
    long long tmp = 0; // 현재 구간의 총 시청자 수
    long long result = 0; // 최대 시청자 수

    // 광고 시작 시점이 0초일 때의 총 시청자 수 계산
    for (int i = 0; i < advtime; i++) {
        tmp += cnt[i];
        q.push(cnt[i]);
    }
    result = tmp;

    // 투 포인터 알고리즘을 이용하여 최적의 광고 시작 시간 탐색
    for (int i = advtime; i < playtime; i++) {
        tmp -= q.front();
        q.pop();
        tmp += cnt[i];
        q.push(cnt[i]);

        // 구간합이 최대일 때의 시작 시간을 기록
        if (result < tmp) {
            result = tmp;
            answer = i - advtime + 1;
        }
    }

    return inttostr(answer);
}
