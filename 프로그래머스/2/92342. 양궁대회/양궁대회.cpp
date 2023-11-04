#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> answer;
int mx = 0;
int N;

void solve(int cnt, int score, vector<int> ap, vector<int> li)
{
    if(cnt == N || score == 10)
    {
        if(score == 10 && cnt != N)
            li[score] = N - cnt;
        int a = 0, l = 0;
        for(int i=0; i<=10; i++)
        {
            if(ap[i] == 0 && li[i] == 0)
                continue;
            if(ap[i] >= li[i])
                a += 10 - i;
            else
                l += 10 - i;
        }
        
        if(mx < l - a && l - a != 0)
        {
            mx = l - a;
            answer = li;
            return;
        }
        else if(mx == l - a)
        {
            for(int i = 10; i>=0; i--)
            {
                if(answer[i] < li[i])
                {
                    answer = li;
                    break;
                }
                else if(answer[i] > li[i])
                    break;
            }
        }
        return;
    }
    
    solve(cnt, score + 1, ap, li);
    if(cnt + ap[score] + 1 <= N)
    {
        li[score] = ap[score] + 1;
        solve(cnt + li[score], score + 1, ap, li);
    }
}
vector<int> solution(int n, vector<int> info) {
    N = n;
    
    vector<int> v;
    v.resize(info.size());
    answer.resize(info.size());
    solve(0, 0, info, v);
    if(mx == 0)
    {
        return {-1};
    }
    return answer;
}