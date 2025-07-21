#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> food_times, long long k) 
{
    int answer = -1; 
    int size = food_times.size();
    
    vector<int> food_times_sorter = food_times;
    
    sort(food_times_sorter.begin(), food_times_sorter.end());
    
    int height = food_times_sorter.front();
    int before_height = 0;
    int max_height = food_times_sorter.back();
    int target_idx = 0;
    while(target_idx < size)
    {
        height = food_times_sorter[target_idx];
        long long value = 1LL * (height - before_height) * (size - target_idx);
        // printf("height = %d  value = %lld \n", height, value);
        if(k < value)
        {
            // printf("Break!");
            break;
        }
        
        k -= value;
        
        // 다음 높이의 idx 탐색
        before_height = height;
        while(target_idx < size && height == food_times_sorter[target_idx])
        {
            target_idx++;
        }
    }
    
    if(target_idx == size) return -1;
    k = k % (size - target_idx) + 1;
    
    int result_idx = 0;
    while(k > 0)
    {
        if(food_times[result_idx] >= height)
        {
            k--;
        }
        result_idx++;
    }
    
    return result_idx;
}