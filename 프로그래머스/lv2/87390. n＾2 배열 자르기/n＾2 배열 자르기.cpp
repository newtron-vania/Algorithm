#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    // [1234...n], [2234...n], [33345...n], ... [(n-1)(n-1)...(n-1)n], [nnnnnnn]
    long long idx = 1 + left/n;
    long long count = left % n;
    for(long long i = left; i <= right; i++){
        if(count < idx){
            answer.push_back(idx);
        }
        else{
            answer.push_back(count+1);
        }
        count += 1;
        if(count%n == 0){
            idx += 1;
            count = 0;
        }
    }
    return answer;
}