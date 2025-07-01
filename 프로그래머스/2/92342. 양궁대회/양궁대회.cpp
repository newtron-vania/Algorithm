#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int n, vector<int> info) 
{
    vector<int> answer(11, -1);
    
    int max_diff = -1;
    
    for(int i = 0; i < (1 << 11); i++)
    {
        int lion_score = 0;
        int peach_score = 0;
        int arrow_count = n;
        vector<int> lion_info(11, 0);
        for(int j = 10; j >= 0; j--)
        {
            if(i & (1 << j))
            {
                if(arrow_count > info[10 - j])
                {
                    lion_score += j;
                    arrow_count -= info[10 - j] + 1;
                    lion_info[10 - j] = info[10 - j] + 1;
                }
                else if(info[10 - j] > 0)
                {
                    peach_score += j;
                }
            }
            else if(info[10 - j] > 0)
            {
                peach_score += j;
            }
            
        }
        lion_info[10] += arrow_count;
        
        int diff = lion_score - peach_score;
        if(diff <= 0) continue;
        if(diff > max_diff)
        {
            max_diff = diff;
            answer = lion_info;
        }
        else if (diff == max_diff)
        {
            // 낮은 점수 많이 쏜 걸 우선시
            for (int i = 10; i >= 0; i--) 
            {
                if (lion_info[i] > answer[i]) 
                {
                    answer = lion_info;
                    break;
                } 
                else if (lion_info[i] < answer[i]) 
                {
                    break;
                }
            }
        }
    }
    
    return max_diff > 0 ? answer : vector<int>{ -1 };
}