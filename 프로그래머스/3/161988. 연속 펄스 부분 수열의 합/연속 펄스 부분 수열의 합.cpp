#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long find_max(vector<int> v)
{
    vector<long long> dp(v.size());
    dp[0] = v[0];

    for(int i=1;i<dp.size();i++) dp[i] = max(1LL*v[i], dp[i-1] + v[i]);
    long long res;
    res = *max_element(dp.begin(), dp.end());
    return res;
}

long long solution(vector<int> sequence)
{
    vector<int> v1(sequence), v2(sequence);
    for(int i=0;i<sequence.size();i++)
    {
        if (i%2) v1[i] *= -1;
        else v2[i] *= -1;
    }
    return max(find_max(v1), find_max(v2));
}