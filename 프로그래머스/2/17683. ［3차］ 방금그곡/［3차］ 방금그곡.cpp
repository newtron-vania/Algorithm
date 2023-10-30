#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <map>
#include <cmath>

using namespace std;

map<char, char> code_map = {{'A','a'}, {'C','c'}, {'D','d'}, {'F','f'}, {'G','g'}};

vector<string> Split(string input, char delimiter);

//시간 return
int TimeToSec(string time);

//코드 개수 가져오는 함수
string SetCode(string m)
{
    string result = "";
    int idx = 0;
    while(idx < m.size())
    {
        if(m[idx+1] == '#')
        {
            result += code_map[m[idx]];
            idx += 2;
        }
        else{
            result += m[idx];
            idx += 1;
        }
    }
    return result;
}


//코드를 가져오는 함수
void GetNextCode(string& code)
{
    code = code.substr(1) + code[0];
}

bool isSame(string input, string finder)
{
    int idx = 0;
    if((idx = input.find(finder)) != -1)
    {
        return true;
    }
    return false;
}


string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    
    m = SetCode(m);
    
    vector<pair<int, vector<string>>> musicVec;
    
    //음악 정보 벡터 추출
    for(string musicinfo : musicinfos)
    {
        vector<string> info = Split(musicinfo, ',');
        
        int time = TimeToSec(info[1]) - TimeToSec(info[0]);
        string key = info[2];
        string codes = info[3];
        string new_codes = "";
        codes =  SetCode(codes);
        //코드 생성
        for(int i = 0; i <  time / codes.size(); i++)
        {
            new_codes += codes;
        }
        
        for(int i = 0; i < time%codes.size(); i++)
        {
            new_codes += codes[i];
        }

        musicVec.push_back(pair<int, vector<string>>(time, {key, new_codes}));
    }
    
    int max_time = 0;
    
    for(auto vec : musicVec)
    {
        if(isSame(vec.second[1], m))
        {
            if(max_time < vec.first)
            {
                max_time = vec.first;
                answer = vec.second[0];
            }
        }
    }
    
    return answer;
}

vector<string> Split(string input, char delimiter)
{
    vector<string> result;
    stringstream ss(input);
    string tmp;
    
    while(getline(ss, tmp, delimiter))
    {
        result.push_back(tmp);
    }
    
    return result;
}

int TimeToSec(string time)
{
    vector<string> times = Split(time, ':');
    return (stoi(times[0]) * 60) + stoi(times[1]);
}
