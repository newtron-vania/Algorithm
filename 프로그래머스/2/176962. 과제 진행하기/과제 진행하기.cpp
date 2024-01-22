#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

bool compare(vector<string> a,vector<string> b){
    if(a[1]==b[1]){
        return a[0]<b[0];
    }
    else{
        return a[1]<b[1];
    }
}
vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    sort(plans.begin(), plans.end(), compare);
    vector<pair<string, int>>stop_mission;
    int cur_time = 0;
    for(int i = 0;i < plans.size(); i++)
    {
        int start_time = (stoi(plans[i][1].substr(0,2)) * 60 + stoi(plans[i][1].substr(3, 2)));
        while(cur_time < start_time)
        {
            if(!stop_mission.empty())
            {
                stop_mission.back().second--;
                if(stop_mission.back().second == 0)
                {
                    answer.push_back(stop_mission.back().first);
                    stop_mission.pop_back();
                }
            }
            cur_time++;
        }
        stop_mission.push_back(make_pair(plans[i][0], stoi(plans[i][2])));
    }
    while(!stop_mission.empty())
    {
        answer.push_back(stop_mission.back().first);
        stop_mission.pop_back();
    }
    return answer;
}