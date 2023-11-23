#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    unordered_map<string, int> want_counts;
    
    for(string w : want)
    {
        want_counts.insert(pair(w, 0));
    }
    
    for(int i = 0; i < discount.size(); i++)
    {
        bool isOver = true;
        if(want_counts.find(discount[i]) != want_counts.end())
        {
            want_counts[discount[i]] += 1;
        }
        if(i >= 10)
        {
            if(want_counts.find(discount[i-10]) != want_counts.end())
            {
                want_counts[discount[i-10]] -= 1;
            }
        }
        
        for(int j = 0; j < want_counts.size(); j++)
        {
            if(want_counts[want[j]] < number[j])
            {
                isOver = false;
                break;
            }
        }
        if(isOver)
        {
            answer += 1;
        }
    }
    return answer;
}