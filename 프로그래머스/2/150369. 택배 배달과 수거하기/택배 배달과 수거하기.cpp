#include <string>
#include <vector>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    int del_size = deliveries.size();
    int del_cnt = 0;
    int pick_cnt = 0;
    for(int idx = del_size-1; idx >= 0; idx--)
    {
        del_cnt += deliveries[idx];
        pick_cnt += pickups[idx];
        
        while(del_cnt > 0  || pick_cnt > 0)
        {
            del_cnt -= cap;
            pick_cnt -= cap;
            answer += 2 * (idx+1);
        }
    }
    return answer;
}