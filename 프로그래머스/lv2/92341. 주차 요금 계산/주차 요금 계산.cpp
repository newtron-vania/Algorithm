#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

vector<string> Split(string str, char delimeter);

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    int basicTime = fees[0];
    int basicTex = fees[1];
    int basicTerm = fees[2];
    int basicTermTex = fees[3];
    
    map<string, int> recordDict;
    map<string, int> recordAnswer;
    for(string record : records){
        vector<string> str = Split(record, ' ');
        int time = stoi(str[0].substr(0,2)) * 60 + stoi(str[0].substr(3,2));
        if(str[2] == "IN"){
            recordDict[str[1]] = time;
        }
        else{
            recordAnswer[str[1]] += time - recordDict[str[1]];
            recordDict[str[1]] = -1;
        }
    }

    for(auto& itr : recordDict){
        if(itr.second >= 0){
            recordAnswer[itr.first] += 24*60 - 1 - itr.second;
            itr.second = 0;
        }
        int texResult = basicTex + max(0,((recordAnswer[itr.first] - basicTime) / basicTerm + ((recordAnswer[itr.first] - basicTime) % basicTerm > 0 ? 1 : 0))) * basicTermTex;
        answer.push_back(texResult);
    }
    return answer;
}

vector<string> Split(string str, char delimeter){
    string tmp;
    vector<string> result;
    istringstream ss(str);
    while(getline(ss, tmp, delimeter)){
        result.push_back(tmp);
    }
    return result;
}