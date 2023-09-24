#include <string>
#include <vector>

using namespace std;

bool isEven(int a){
    int count = 0;
    for(int i = 1; i*i<= a; i++){
        if(i*i == a) count += 1;
        else if(a%i == 0) count += 2;
    }
    return count%2 == 0;
}

int solution(int left, int right) {
    int answer = 0;
    for(int i = left; i <= right; i++){
        answer += isEven(i) ? i : -1 * i;
    }
    return answer;
}