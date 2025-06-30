#include <bits/stdc++.h>

using namespace std;

vector<string> split(string input, char delimiter);

vector<int> solution(vector<string> infos, vector<string> querys) 
{
    vector<int> answer;
    
    unordered_map<string, vector<int>> map_infos;
    
    for(const auto& info : infos)
    {
        auto split_info = split(info, ' ');
        for(int i = 0; i < 16; i++)
        {
            string tmp = "";
            for(int j = 0; j < 4; j++)
            {
                tmp += (i & (1 << j)) ? split_info[j] : "-";
            }
            map_infos[tmp].push_back(stoi(split_info.back()));
        }
    }
    
    for (auto it = map_infos.begin(); it != map_infos.end(); ++it)
    {
        vector<int>& values = it->second;
        sort(values.begin(), values.end());
    }
    
    for(const auto& q : querys)
    {
        auto split_query = split(q, ' ');
        string key = split_query[0] + split_query[2] + split_query[4] + split_query[6];
        int v = 0;
        
        if(map_infos.find(key) != map_infos.end())
        {
            auto scores = map_infos[key];
            v = scores.end() - lower_bound(scores.begin(), scores.end(), stoi(split_query.back()));
        }
        
        answer.push_back(v);
    }
    
    return answer;
}

vector<string> split(string input, char delimiter) 
{
    vector<string> answer;
    stringstream ss(input);
    string temp;

    while (getline(ss, temp, delimiter))
    {
        answer.push_back(temp);
    }

    return answer;
}
