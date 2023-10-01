#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    unordered_map<string, int> dict;
    for(int i = 0; i < 26; i++){
        string tmp = "";
        tmp += 'A' + i;
        dict[tmp] = i+1;
    }
    
    //현재 문자열 위치
    int idx = 0;
    //색인 번호
    int value = 26;
    
    string tmp = "";
    while(idx < msg.length()){
        if(dict.find(tmp + msg[idx]) == dict.end()){
            answer.push_back(dict[tmp]);
            dict[tmp + msg[idx]] = ++value;
            tmp = "";
        }
        tmp += msg[idx++];
    }
    
    answer.push_back(dict[tmp]);
    return answer;
}