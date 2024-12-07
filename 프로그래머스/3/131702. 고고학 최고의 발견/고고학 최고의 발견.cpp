#include <bits/stdc++.h>
using namespace std;

int offsetY[5] { 0, 0, 0, 1, -1 };
int offsetX[5] { 0, -1, 1, 0, 0 };
int result = INT_MAX;

void rotate(vector<vector<int>>& clockHands, int y, int x, int count, bool isClockwise = true)
{
    for (int i = 0; i < 5; ++i)
    {
        int yy = y + offsetY[i];
        int xx = x + offsetX[i];
        if (yy == -1 || xx == -1 || yy == clockHands.size() || xx == clockHands.size())
        {
            continue;
        }
        clockHands[yy][xx] = (clockHands[yy][xx] + (isClockwise ? count : -count) + 4) % 4;
    }
}

bool check(vector<vector<int>>& clockHands)
{
    for (int i = 0; i < clockHands.size(); ++i)
    {
        for (int j = 0; j < clockHands.size(); ++j)
        {
            if (clockHands[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

int DFS(vector<vector<int>>& clockHands, int row, int col, int cnt)
{
    if (check(clockHands))
    {
        return cnt;
    }
    if (row == clockHands.size())
    {
        return INT_MAX;  
    }
    if (cnt >= result)
    {
        return INT_MAX;
    }
    for (int i = 0; i < 4; ++i)
    {
        rotate(clockHands, row, col, i, true);

        if (row && clockHands[row - 1][col])
        {
            rotate(clockHands, row, col, i, false);
            continue;
        }

        int nextRow = (col + 1 == clockHands.size()) ? row + 1 : row;
        int nextCol = (col + 1) % clockHands.size();
        result = min(result, DFS(clockHands, nextRow, nextCol, cnt + i));
        rotate(clockHands, row, col, i, false);
    }
    return result;
}

int solution(vector<vector<int>> clockHands)
{
    return DFS(clockHands, 0, 0, 0);
}
