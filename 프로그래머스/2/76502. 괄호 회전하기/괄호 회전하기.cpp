#include <string>
#include <vector>
#include <iostream>

using namespace std;



int solution(string s) {
    int answer = 0;

    vector<char> stack;
    vector<int> rotateIdx;
    int cnt = 0;
    bool isTrue = false;
    string checkstr = "]})";
    for (int i = 0; i < s.size(); i++)
    {
        if (checkstr.find(s[i]) != string::npos)
        {
            rotateIdx.push_back(i+1);
        }
    }

    for (int i = rotateIdx.size()-1; i >0; i--) 
    {
        rotateIdx[i] -= rotateIdx[i-1];
    }


    int num = 0;
    while (cnt < s.size()) 
    {
        isTrue = true;
        stack.clear();
        for (char c : s) 
        {
            if (checkstr.find(c) == string::npos)
            {
                stack.push_back(c);
            }
            else 
            {
                if (stack.empty())
                {
                    isTrue = false;
                    break;
                }
                if (stack.back() == '[')
                    if (c == ']')
                        stack.pop_back();
                    else 
                    {
                        isTrue = false;
                        break;
                    }
                else if (stack.back() == '{')
                    if (c == '}')
                        stack.pop_back();
                    else
                    {
                        isTrue = false;
                        break;
                    }
                else if (stack.back() == '(')
                    if (c == ')')
                        stack.pop_back();
                    else
                    {
                        isTrue = false;
                        break;
                    }
            }
        }

        if (stack.empty() && isTrue)
            answer++;
        if (num >= rotateIdx.size())
            break;
        s = s.substr(rotateIdx[num], s.size() - rotateIdx[num]) + s.substr(0, rotateIdx[num]);
        cnt += rotateIdx[num];
        num++;
        
    }

    return answer;
}