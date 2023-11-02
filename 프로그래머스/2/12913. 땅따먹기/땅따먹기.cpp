#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> land)
{
    int answer = 0;
    int size = land.size();
    

    for(int col = 1; col < size; col++)
    {
        for(int idx = 0; idx < 4; idx++)
        {
            land[col][idx] += max(*max_element(land[col-1].begin()-1,land[col-1].begin()+idx),
                                 *max_element(land[col-1].begin()+idx+1, land[col-1].end()));
        }
    }
    answer = *max_element(land[size-1].begin(), land[size-1].end());

    
    return answer;
}