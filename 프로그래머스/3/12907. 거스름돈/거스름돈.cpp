#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 100001;
const int DIV_VALUE = 1000000007;
int dp[MAX];

int solution(int n, vector<int> moneys) {
    int answer = 0;
    dp[0] = 1;
    
    for(int money : moneys)
    {
        for(int i = money; i<=n; i++)
        {
            dp[i] = (dp[i] + dp[i - money]) % DIV_VALUE;
        }
    }
    answer = dp[n];
    return answer;
}