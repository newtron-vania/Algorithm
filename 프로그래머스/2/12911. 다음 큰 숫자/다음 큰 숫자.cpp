#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int original) {
    int n = original;
    int answer = original;
    int to_one_idx = 0;
    //2진수 변환 시 1인 곳
    while(!(n%2))
    {
        to_one_idx++;
        n /= 2;
    }
    //2진수 변환 시 0인 곳
    while(n%2)
    {
        to_one_idx++;
        n /= 2;
    }
    
    answer |= 1 << to_one_idx;
    answer &= ~(1 << (to_one_idx-1));
    if(!(answer & 1) && to_one_idx >= 2 &&answer & (1 << (to_one_idx-2)))
    {
        answer &= ~(1 << (to_one_idx-2));
        answer |= 1;
    }
    
    return answer;
}