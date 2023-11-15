#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer(right - left + 1, 0);
    // [1234...n], [2234...n], [33345...n], ... [(n-1)(n-1)...(n-1)n], [nnnnnnn]
    for(long long i = left; i <= right; i++){
        answer[i - left] = max(i/n, i%n)+1;
    }
    return answer;
}