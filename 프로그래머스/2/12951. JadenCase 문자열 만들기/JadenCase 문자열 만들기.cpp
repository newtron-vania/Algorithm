#include <string>
#include <vector>
#include <sstream>

using namespace std;

string solution(string s) {
    string answer = "";
    
    bool start = true;
    for(int i = 0; i < s.length(); i++)
    {
        if(isspace(s[i]))
        {
            start = true;
        }
        else
        {
            if(!isdigit(s[i]))
            {
                if(start)
                {
                    s[i] = toupper(s[i]);
                }
                else
                {
                    s[i] = tolower(s[i]);
                }
            }
            start = false;
        }
        answer += s[i];
    }
    
    return answer;
}