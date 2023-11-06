#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> sticker)
{
    int answer = 0;
    int size = sticker.size();
    if(size == 1)
        return sticker[0];
    
    vector<pair<int, int>> dp(size, pair<int, bool>(0, 0));
    //처음을 찢었을 때, 찢지 않았을 때
    dp[0] = pair(sticker[0], 0);
    dp[1] = pair(sticker[0], sticker[1]);
    //점화식 : dp[n] = max(dp[n-1], dp[n] + dp[n-2])
    bool first_last = false;
    for(int i = 2; i < size-1; i++)
    {
        int first = max(dp[i-1].first, sticker[i] + dp[i-2].first);
        first_last = dp[i-1].first < sticker[i] + dp[i-2].first;
        int second = max(dp[i-1].second, sticker[i] + dp[i-2].second);
        dp[i] = pair(first, second);
    }
    dp[size-1] = pair(dp[size-2].first, max(dp[size-2].second, sticker[size-1] + dp[size-3].second));
    answer = max(dp[size-1].first, dp[size-1].second);
    return answer;
}