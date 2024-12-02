#include <bits/stdc++.h>


using namespace std;

int solution(vector<int> diffs, vector<int> times, long long limit) 
{
    
    int minLevel = 1;
    int maxLevel = *max_element(diffs.begin(), diffs.end());
    
    int answer = maxLevel;
    while (minLevel <= maxLevel)
    {
        int curLevel = (minLevel + maxLevel) / 2;
        
        long long time = 0;
        for (int i = 0; i < times.size(); i++)
        {
            int prev = i == 0 ? 1 : times[i-1];
            time += max(diffs[i]-curLevel, 0) * (times[i] + prev) + times[i];
        }
        
        if (time <= limit)
        {
            maxLevel = curLevel - 1;
            answer = min(answer, curLevel);
        }
        else
            minLevel = curLevel + 1;
    }
    
    return answer;
}