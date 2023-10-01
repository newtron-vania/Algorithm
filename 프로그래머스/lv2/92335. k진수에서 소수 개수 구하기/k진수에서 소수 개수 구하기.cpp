#include <string>
#include <vector>
#include <iostream>
#include <cctype>

using namespace std;

bool isPrime(long long n){
    if(n < 2)
        return false;
    for(long long i = 2; i*i <= n; i++){
        if(n%i == 0){
           return false; 
        }
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    string tmp = "";
    while(n>0){
        int c = n%k;
        n /= k;
        tmp = to_string(c) + tmp;
        if(!c || !n){
            long long num = stoull(tmp);
            if(isPrime(num)) answer++;
            tmp = "";
        }
    }
    return answer;
}