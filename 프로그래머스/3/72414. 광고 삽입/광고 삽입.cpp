#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 각 초에 대한 재생 횟수를 저장하는 배열
const int MAX_VALUE = 360000;
long long cnt[MAX_VALUE+1];

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
    
    fill_n(cnt, MAX_VALUE+1, 0);
    
    int playtime = strtoint(play_time); // 동영상 총 재생 시간
    int advtime = strtoint(adv_time); // 광고 재생 시간
    
    // 로그를 분석하여 각 초마다 시청자 수 계산
    for (int i = 0; i < logs.size(); i++) {
        int start = strtoint(logs[i].substr(0, 8));
        int end = strtoint(logs[i].substr(9));
        
        cnt[start]++;
        cnt[end]--;
    }
    
    for(int i = 1; i <= playtime; i++)
    {
        cnt[i] += cnt[i-1];
    }
    
    for(int i = 1; i <= playtime; i++)
    {
        cnt[i] += cnt[i-1];
    }

    long long tmp = cnt[advtime - 1]; // 현재 구간의 총 시청자 수
    long long result = tmp; // 최대 시청자 수

    // 슬라이딩 윈도우 알고리즘을 통한 구간합 계산
    for (int i = 1; i <= playtime - advtime; i++) {
        tmp = cnt[i + advtime - 1] - cnt[i - 1];

        // 구간합이 최대일 때의 시작 시간을 기록
        if (result < tmp) {
            result = tmp;
            answer = i;
        }
    }

    return inttostr(answer);
}
