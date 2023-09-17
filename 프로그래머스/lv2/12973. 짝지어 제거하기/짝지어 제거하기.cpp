#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

int solution(string s)
{
    stack<char> stk;
    for(char i : s){
        if(stk.size() >= 1 && stk.top() == i)
        {
            stk.pop();
        }
        else
            stk.push(i);
    }
    if(stk.size()>0)
        return 0;
    else
        return 1;
}