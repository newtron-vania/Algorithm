#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int idx = 0;
    vector<int> results;
    string tmp = "";
    while(idx < dartResult.length()){
        if(isdigit(dartResult[idx])){
            tmp += dartResult[idx];
        }
        else if( 'A' <= dartResult[idx] && dartResult[idx] <= 'Z'){
            int value = stoi(tmp);
            if(dartResult[idx] == 'S'){
                results.push_back(value);
            }
            else if(dartResult[idx] == 'D'){
                results.push_back(value * value);
            }
            else if(dartResult[idx] == 'T'){
                results.push_back(value * value * value);
            }
            tmp = "";
        }
        else{
            if(dartResult[idx] == '*'){
                for(auto itr = results.end()-1; itr != results.end()-3; --itr){
                    *itr *= 2;
                }
            }
            if(dartResult[idx] == '#'){
                *(results.end()-1) *= -1;
            }
            
        }
        idx++;
    }
    for(auto itr = results.begin(); itr != results.end(); ++itr){
        answer += *itr;
    }
    return answer;
}