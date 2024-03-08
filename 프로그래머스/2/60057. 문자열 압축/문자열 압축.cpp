#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s) 
{
    vector<int> answer;
    int cnt = 1;
    
    if (s.length() < 2) 
    {
        return 1;
    }
    
    while (cnt <= s.length() / 2) 
    {
        string ret = "";
        int a = 1;
        
        for (int i = 0; i < s.length(); i += cnt) 
        {
            if (i + cnt * 2 <= s.length() && s.substr(i, cnt) == s.substr(i + cnt, cnt)) 
            {
                a++;
            } 
            else 
            {
                if (a > 1) 
                {
                    ret += to_string(a) + s.substr(i, cnt);
                    a = 1;
                } 
                else 
                {
                    ret += s.substr(i, min(cnt, static_cast<int>(s.length() - i)));
                }
            }
        }
        
        answer.push_back(ret.length());
        cnt++;
    }
    
    return *min_element(answer.begin(), answer.end());
}