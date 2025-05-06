#include <bits/stdc++.h>
using namespace std;

int N, L, answer = 0;
int pan[100][100];

bool IfCanLine(const vector<int>& line)
{
    vector<bool> bridge(N, false);

    for (int i = 1; i < N; i++)
    {
        int diff = line[i - 1] - line[i];
        if (abs(diff) > 1)
        {
            return false;
        }

        if (diff == 1) // 경사로를 오른쪽으로
        {
            for (int j = 0; j < L; j++)
            {
                int idx = i + j;
                if (idx >= N || line[idx] != line[i] || bridge[idx])
                {
                    return false;
                }
                bridge[idx] = true;
            }
        }
        else if (diff == -1) // 경사로를 왼쪽으로
        {
            for (int j = 0; j < L; j++)
            {
                int idx = i - 1 - j;
                if (idx < 0 || line[idx] != line[i - 1] || bridge[idx])
                {
                    return false;
                }
                bridge[idx] = true;
            }
        }
    }
    return true;
}

int main()
{
    cin >> N >> L;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> pan[i][j];
        }
    }

    for (int i = 0; i < N; i++)
    {
        vector<int> row;
        for (int j = 0; j < N; j++)
        {
            row.push_back(pan[i][j]);
        }
        if (IfCanLine(row))
        {
            answer++;
        }
    }

    for (int j = 0; j < N; j++)
    {
        vector<int> column;
        for (int i = 0; i < N; i++)
        {
            column.push_back(pan[i][j]);
        }
        if (IfCanLine(column))
        {
            answer++;
        }
    }

    cout << answer << endl;
    return 0;
}