#include <string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    
    int count = 0;
    
    for(char c : s)
    {
        count += c == '(' ? 1 : -1;
        if(count < 0)
        {
            answer = false;
            break;
        }
    }
    if(count != 0)
        answer = false;
    return answer;
}