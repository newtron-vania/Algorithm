#include <iostream>
#include <string>
#include <vector>

const int INF =  987654321;
#define MINI(A,B) A>B ? B : A
    
using namespace std;

int dp[20002];
int solution(vector<string> strs, string t)
{
    bool flag = true;
    int answer = -1;
    int before_idx;
    for(int i=1;i<=t.length();i++) 
    {
        dp[i] = INF;
    }
    for(int i = 1; i <= t.length(); i++) 
    {
        for(int j = 0;j < strs.size(); j++) 
        {
            before_idx = i-strs[j].length();
            if(before_idx < 0) 
                continue;
            flag = true;
            for(int k = 0; k < strs[j].length(); k++) 
            {
                if(t[before_idx+k] != strs[j][k]) 
                {
                    flag=false;
                    break;
                }
            }
            if(flag) {
                dp[i] = MINI(dp[i], dp[before_idx] + 1);
            }
        }
    }
    answer = dp[t.length()];
    if(answer == INF) answer = -1;
    return answer;
}
