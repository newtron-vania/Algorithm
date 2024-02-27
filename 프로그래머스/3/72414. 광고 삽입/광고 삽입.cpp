#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int cnt[360000];

int strtoint(string s) {
    string sec = s.substr(6, 2);
    string min = s.substr(3, 2);
    string hour = s.substr(0, 2);

    int result = stoi(sec) + stoi(min) * 60 + stoi(hour) * 60 * 60;
    return result;
}

string inttostr(int i) {
    int sec = i % 60;
    i /= 60;
    int min = i % 60;
    i /= 60;
    int hour = i;
    string result = "";
    if(hour<10)result+="0";
    result += to_string(hour);
    result += ":";
    if (min < 10)result += "0";
    result += to_string(min);
    result += ":";
    if (sec < 10)result += "0";
    result += to_string(sec);
    
    return result;
}


string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    //각 재생시간에 해당하는 구간에 +1
    for (int i = 0; i < logs.size(); i++) 
    {
        int start = strtoint(logs[i].substr(0, 8));
        int end = strtoint(logs[i].substr(9));
        for (int j = start; j < end; j++) 
        {
            cnt[j]++;
        }
    }
    
    int playtime = strtoint(play_time); //총 재생시간
    int advtime = strtoint(adv_time); //광고시간

    queue<int> q; //가장 첫 원소를 빼고 뒤에 삽입하기 때문에 큐사용
    int index = 0; //결정된 광고 시작시간
    long long tmp = 0; 
    long long result = 0;

    //0초부터 시작했을때 구간합
    for (int i = 0; i < advtime; i++) 
    {
        tmp += cnt[i];
        q.push(cnt[i]);
    }

    result = tmp;
    
    //투 포인터 알고리즘 
    for (int i=advtime; i < playtime; i++) 
    { 
        tmp -= q.front();
        q.pop();
        tmp += cnt[i];
        q.push(cnt[i]);
        
        //구간합이 최대일때
        if (result < tmp) 
        {
            result = tmp;
            index = i - advtime + 1;
        }
    }
    answer = inttostr(index);

    return answer;
}