#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> food_times, long long k) {
    int answer = -1;
    int size = food_times.size();

    vector<int> food_times_sorter = food_times;
    food_times_sorter.push_back(0);
    sort(food_times_sorter.begin(), food_times_sorter.end());

    for(int i = 1; i <= size; i++){
        long long time = 1LL * (food_times_sorter[i] - food_times_sorter[i-1]) * (size - i+1);
        if(time <= k){
            k -= time;
            continue;
        }

        long long count = k % (size - i + 1);
        int idx = 0;
        long long limit = food_times_sorter[i];

        while(true){
            if(food_times[idx] >= limit){
                count--;
                if(count < 0)
                    break;
            }
            idx++;
        }
        answer = idx;
        break;
    }
    return answer >= 0 ? answer + 1 : -1;
}