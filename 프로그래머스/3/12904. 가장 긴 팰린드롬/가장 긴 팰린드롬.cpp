#include <iostream>
#include <string>

using namespace std;

int solution(string s){

    int answer = 1; 
    s.push_back(1);

    for(size_t i = 1; i < s.size(); i++){
        int left = i - 1, right = i + 1, count_1 = 0, count_2 = 1;
        bool f1 = false, f2 = false;

        while(left >= 0 && right < s.size()){
            
            if(s[left] == s[right - 1]) count_1 += 2;
            else f1 = true;

            if(s[left--] == s[right++]) count_2 += 2; 
            else f2= true;

            if(f1 && f2) break;       
        }

        int result = (count_1 > count_2) ? count_1 : count_2;
        answer = (result > answer) ? result : answer;
    }
    return answer;
}