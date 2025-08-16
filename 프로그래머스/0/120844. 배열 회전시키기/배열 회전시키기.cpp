#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> numbers, string direction) 
{
    deque<int> dq(numbers.begin(), numbers.end());

    if (direction == "right")
        rotate(dq.rbegin(), dq.rbegin() + 1, dq.rend()); 
    else
        rotate(dq.begin(), dq.begin() + 1, dq.end());

    return vector<int>(dq.begin(), dq.end());
}