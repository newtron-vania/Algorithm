#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    string n_str = "";
    while(n > 0){
        n_str += to_string(n%3);
        n /= 3;
    }
    int size = n_str.length();
    for(int i = 1; i <= size; i++){
        int a = n_str[size - i] - '0';
        for(int j = 1; j<i; j++){
            a *= 3;
        }
        answer += a;
    }
    return answer;
}