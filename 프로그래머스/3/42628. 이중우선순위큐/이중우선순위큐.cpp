#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>

using namespace std;

vector<string> split(string str, char delimiter);

void pop_front(vector<int> &v){
    if(v.size()>0)
        v.erase(v.begin());
}

void pop_back(vector<int> &v){
    if(v.size()>0)
        v.pop_back();
}

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    for(string s : operations)
    {
        vector<string> cmd = split(s, ' ');
        if(cmd[0].compare("I") == 0){
            answer.push_back(stoi(cmd[1]));
        }
        else
        {
            sort(answer.rbegin(), answer.rend());
            if(cmd[1].compare("1") == 0)
            {
                pop_front(answer);
            }
            else
            {
                if(answer.size() > 0)
                    pop_back(answer);
            }
        }
    }
    
    sort(answer.rbegin(), answer.rend());
    for(int i : answer){
        cout << i << endl;
    }
    if(answer.size() > 0)
        return {answer.front(), answer.back()};
    else
        return {0,0};
}

vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;
 
    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }
 
    return answer;
}