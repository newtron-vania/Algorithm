#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int column = 0;
bool comp1(vector<int>& a, vector<int>& b)
{
    if(a[column] == b[column])
    {
        return a[0] > b[0];
    }
    return a[column] < b[column];
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    column = col-1;
    sort(data.begin(), data.end(), comp1);
    
    for(int i = row_begin-1; i < row_end; i++)
    {
        int totalSum = 0;
        for(int j = 0; j < data[0].size(); j++)
        {
            totalSum += data[i][j] % (i+1);
        }
        answer ^= totalSum;
    }
    return answer;
}