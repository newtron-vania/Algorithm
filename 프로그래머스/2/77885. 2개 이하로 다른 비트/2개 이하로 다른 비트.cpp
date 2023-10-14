#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long GetNextNumber(long long number, int cnt){
    long long k = 1LL;
    for(int i = 0; i < cnt; i++){
        k *= 2;
    }
    number += k - (k/2);
    return number;
}
vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for(long long number : numbers){
        int cnt = 0;
        long long num = number;
        while(num > 0){
            if(!(num % 2)){
                break;
            }
            num /= 2;
            cnt++;
        }
        answer.push_back(GetNextNumber(number, cnt));
    }
    return answer;
}