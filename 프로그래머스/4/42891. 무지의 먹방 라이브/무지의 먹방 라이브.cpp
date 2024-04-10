#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> food_times, long long k) {
    int answer = -1; // 음식이 남아 있지 않음을 나타내기 위해 -1로 초기화합니다.
    int size = food_times.size(); // food_times 벡터의 크기를 가져옵니다.

    // food_times의 정렬된 복사본을 만들고, 시작 부분에 0을 추가합니다.
    vector<int> food_times_sorter = food_times;
    food_times_sorter.push_back(0);
    sort(food_times_sorter.begin(), food_times_sorter.end());

    // 각 음식이 먹히기 시작하는 시간을 계산합니다.
    for(int i = 1; i <= size; i++){
        long long time = 1LL * (food_times_sorter[i] - food_times_sorter[i-1]) * (size - i+1);
        // 해당 시간이 k보다 작거나 같으면 k에서 시간을 뺍니다.
        if(time <= k){
            k -= time;
            continue;
        }

        // 남은 시간동안에 어떤 음식을 먹게 될지 계산합니다.
        long long count = k % (size - i + 1);
        int idx = 0;
        long long limit = food_times_sorter[i];

        // 남은 시간동안에 먹게 될 음식의 인덱스를 찾습니다.
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
    // 계산된 인덱스가 유효한지 확인하고 반환합니다.
    return answer >= 0 ? answer + 1 : -1;
}