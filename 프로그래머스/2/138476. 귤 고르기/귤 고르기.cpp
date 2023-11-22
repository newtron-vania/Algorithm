#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b)
{
    return a.second > b.second;
}

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    
    unordered_map<int, int> tangerine_counts;
    
    for(int tg : tangerine)
    {
        tangerine_counts[tg] += 1;
    }
    
    vector<pair<int, int>> vec(tangerine_counts.begin(), tangerine_counts.end());
    sort(vec.begin(), vec.end(), comp);

    int sum = 0;
    for (auto elem : vec)
    {
        sum += elem.second;
        answer++;
        if(sum >= k)
        {
            break;
        }
    }
    
    
    return answer;
}