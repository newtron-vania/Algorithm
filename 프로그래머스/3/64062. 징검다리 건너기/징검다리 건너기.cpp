#include <bits/stdc++.h>

using namespace std;

bool binary_check(vector<int>& stones, int k, int mid)
{
    int cnt = 0;
    for(int i = 0; i < stones.size(); i++)
    {
        if(stones[i] - mid < 0) cnt += 1;
        else cnt = 0;
        if(cnt >= k) return false;
    }
    return true;
}

int solution(vector<int> stones, int k) 
{
    int answer = 0;
    int left = 1;
    int right = *max_element(stones.begin(), stones.end());
    
    while(left <= right)
    {
        int mid = (left + right) / 2;
        if(binary_check(stones, k, mid))
        {
            answer = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return answer;
}