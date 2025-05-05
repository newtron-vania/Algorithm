#include <bits/stdc++.h>

using namespace std;

vector<deque<char>> s(4);

void left(int num, int direction)
{
    if (num < 0) return;
    if (s[num][2] != s[num + 1][6])
    {
        left(num - 1, -direction);
        if (direction == 1)
        {
            char back = s[num].back();
            s[num].pop_back();
            s[num].push_front(back);
        }
        else
        {
            char front = s[num].front();
            s[num].pop_front();
            s[num].push_back(front);
        }
    }
}

void right(int num, int direction)
{
    if (num > 3) return;
    if (s[num][6] != s[num - 1][2])
    {
        right(num + 1, -direction);
        if (direction == 1)
        {
            char back = s[num].back();
            s[num].pop_back();
            s[num].push_front(back);
        }
        else
        {
            char front = s[num].front();
            s[num].pop_front();
            s[num].push_back(front);
        }
    }
}

int main()
{
    for (int i = 0; i < 4; ++i)
    {
        string input;
        cin >> input;
        for (char c : input)
        {
            s[i].push_back(c);
        }
    }

    int K;
    cin >> K;
    vector<pair<int, int>> R(K);
    for (int i = 0; i < K; ++i)
    {
        cin >> R[i].first >> R[i].second;
    }

    for (int i = 0; i < K; ++i)
    {
        int num = R[i].first - 1;
        int direction = R[i].second;
        left(num - 1, -direction);
        right(num + 1, -direction);
        if (direction == 1)
        {
            char back = s[num].back();
            s[num].pop_back();
            s[num].push_front(back);
        }
        else
        {
            char front = s[num].front();
            s[num].pop_front();
            s[num].push_back(front);
        }
    }

    int res = 0;
    if (s[0][0] == '1') res += 1;
    if (s[1][0] == '1') res += 2;
    if (s[2][0] == '1') res += 4;
    if (s[3][0] == '1') res += 8;

    cout << res << endl;
    return 0;
}
