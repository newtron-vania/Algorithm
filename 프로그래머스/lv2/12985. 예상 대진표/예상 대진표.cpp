#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    int size = 0;
    while(n>0){
        size += 1;
        n/=2;
    }
    
    for(int i = 1; i <size; i++){
        a = (a+1)/2;
        b = (b+1)/2;
        answer += 1;
        if(a == b ) return answer;
    }
    return answer;
}