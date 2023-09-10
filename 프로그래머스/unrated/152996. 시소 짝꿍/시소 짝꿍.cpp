#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

const int MAX = 1001;
    
long long solution(vector<int> weights) {
    long long answer = 0;
    int cnt[MAX];
    fill_n(cnt, MAX, 0);
    for(int w : weights){
        cnt[w] += 1;
    }
    
    for(int w = 100; w < MAX; w++){
        int count = 0;
        int base = 0;
        //2:3
        if(w%2 == 0){
            base = w/2*3;
            if(base < MAX) count += cnt[base];
        }
        //3:4
        if(w%3 == 0){
            base = w/3*4;
            if(base < MAX) count += cnt[base];
        }
        //2:4 = 1:2
        base = w*2;
        if(base < MAX) count += cnt[base];
        answer += ((long long)count * cnt[w]);
        answer += ((long long)cnt[w] * (cnt[w]-1)) /2;
    }
    return answer;
}
