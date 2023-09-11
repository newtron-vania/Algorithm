#include <string>
#include <iostream>
#include <algorithm>
#include <regex>
#include <vector>

using namespace std;


vector<int> solution(string s){
        int zeros{0}, num_transform{0}; vector<bool> bin;
    for_each(s.begin(),s.end(),[&bin](const char c){bin.emplace_back(c=='1');});  //s를 이진수로 변환
    while(true){
        if(bin==vector<bool>{true}) break;
        int ones = count(bin.cbegin(),bin.cend(),true);    //1갯수를 셈
        zeros += bin.size()-ones;                          //0갯수를 셈
        bin.clear();
        while(ones>0){ bin.emplace_back(ones%2); ones/=2; }//1갯수를 2진수로 바꿈. 순서는 거꾸로지만 계산에는 영향없음
        ++num_transform;                                   //이진변환 횟수 기록
    }
    return {num_transform,zeros};
}
/**vector<int> solution(string s) {
    vector<int> answer;
    int count = 0;
    int zero = 0;
    
    while(s.size() > 1){
        string x;
        for(char str : s){
            if(str == '0'){
                zero++;
            }
            else{
                x += str;
            }
        }
        int size = x.size();
        s = "";
        while(size > 0){
            s = to_string(size & 1) + s;
            size = size >> 1;
        }
        count++;
        cout << s << endl;
    }
    answer.push_back(count);
    answer.push_back(zero);
    return answer;
}**/