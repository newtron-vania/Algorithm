#include <string>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

const int MAX = INT_MAX;
void dfs(int cnt, int tmp, int &answer){
    if(tmp <= 2){
        answer = min(cnt + tmp, answer);
        return;
    }
    int a = tmp%10;
    tmp /= 10;
    dfs(cnt + a,tmp, answer);
    dfs(cnt + 10-a, tmp+1, answer);
    return;
}

int solution(int storey) {
    int answer = MAX;
    dfs(0, storey, answer);
    return answer;
}