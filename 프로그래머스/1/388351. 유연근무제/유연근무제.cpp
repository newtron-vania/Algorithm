#include <bits/stdc++.h>

using namespace std;

int toMinute(int v)
{
    int minute = (v / 100) * 60 + (v % 100);
    return minute;
}

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) 
{
    int answer = 0;
    
    for(int i = 0; i < schedules.size(); i++)
    {
        schedules[i] = toMinute(schedules[i]);
    }
    
    for(int i = 0; i < timelogs.size(); i++)
    {
        int v = 0;
        int day = startday;
        for(int j = 0; j < timelogs[i].size(); j++)
        {
            if(day % 7 == 0 || day % 7 == 6)
            {
                day++;
                continue;
            }
            timelogs[i][j] = toMinute(timelogs[i][j]);
            int time = schedules[i];
            if(timelogs[i][j] <= time + 10)
            {
                v++;
            }
            day++;
        }
        if(v == 5) answer++;
    }

    return answer;
}
