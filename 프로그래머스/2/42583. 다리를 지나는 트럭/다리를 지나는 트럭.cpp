#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int temp = 0;
    queue<int> que;
    int i = 0;
    while(i < truck_weights.size())
    {
        if(temp + truck_weights[i] <= weight)
        {
            if(que.size() == bridge_length)
            {
                temp -= que.front();
                que.pop();
            }
            que.push(truck_weights[i]);
            temp += truck_weights[i];
            i++;
        }
        else
        {
            if(que.size() < bridge_length)
                que.push(0);
            else
            {
                temp -= que.front();
                que.pop();
                if(temp+truck_weights[i] > weight)
                    que.push(0);
                else
                {
                    que.push(truck_weights[i]);
                    temp += truck_weights[i];
                    i++;
                }
            }
        }
        answer++;
    }
    answer += bridge_length;
    return answer;
}