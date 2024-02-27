
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare1(vector<int> a, vector<int> b) 
{
    if (a[0] > b[0]) 
    {
        return true;
    }
    else if (a[0] == b[0]) 
    {
        return a[1] < b[1];
    }
    return false;
}

bool compare2(const pair<string, int>& a, const pair<string, int>& b)
{
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, vector<vector<int>>> sortDB;
    map<string, int> scoreDB;

    for (int i = 0; i < genres.size(); i++) 
    {
        sortDB[genres[i]].push_back({ plays[i], i });
        scoreDB[genres[i]] += plays[i];
    }

    for (auto& itr : sortDB) 
    {
        sort(itr.second.begin(), itr.second.end(), compare1);
    }
    vector<pair<string, int> > vec;

    for (auto& itr : scoreDB) 
    {
        vec.emplace_back(itr);
    }
    
    sort(vec.begin(), vec.end(), compare2);

    for (auto& itr : vec) 
    {
        int size = sortDB[itr.first].size() >= 2 ? 2 : 1;
        for (int i = 0; i < size; i++)
        {
            answer.push_back(sortDB[itr.first][i][1]);
        }
    }


    return answer;
}