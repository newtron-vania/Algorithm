#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int getDistance(pair<int, int> a, pair<int, int> b)
{
    return abs(a.first - b.first) + abs(a.second - b.second);
}

bool Check(vector<pair<int, int>>& Coordinates, vector<string> place)
{
    for(int start = 0; start < Coordinates.size(); start++)
    {
        auto s_pos = Coordinates[start];
        for(int next = start+1; next < Coordinates.size(); next++)
        {
            auto n_pos = Coordinates[next];
            
            int dist = getDistance(s_pos, n_pos);
            if(dist > 2){
                continue;
            }
            else if(dist == 1)
            {
                return false;
            }
            else
            {
                int min_x, min_y, max_x, max_y;
                if(s_pos.first <= n_pos.first)
                {
                    min_x = s_pos.first;
                    max_x = n_pos.first;
                }
                else
                {
                    min_x = n_pos.first;
                    max_x = s_pos.first;
                }
                if(s_pos.second <= n_pos.second)
                {
                    min_y = s_pos.second;
                    max_y = n_pos.second;
                }
                else
                {
                    min_y = n_pos.second;
                    max_y = s_pos.second;
                }
                for(int x = min_x; x <= max_x; x++)
                {
                    for(int y = min_y; y <= max_y; y++)
                    {
                        if(pair(x, y) == s_pos || pair(x, y) == n_pos){
                            continue;
                        }
                        else
                        {
                            if(place[x][y] != 'X')
                            {
                                return false;
                            }
                        }
                    }
                }
            }
        }
    }
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    int n = places[0].size();
    int m = places[0][0].length();
    for(vector<string> place : places)
    {
        vector<pair<int, int>> Coordinates;
        for(int col = 0; col < n; col++)
        {
            for(int row = 0; row < m; row++)
            {
                if(place[col][row] == 'P')
                {
                    Coordinates.push_back(pair(col, row));
                }
            }
        }
        
        answer.push_back(Check(Coordinates, place));
    }
    return answer;
}