#include <bits/stdc++.h>

using namespace std;

const int MAX = 101;

int board[MAX][MAX];
int freq[MAX];

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int r, c, k;
    cin >> r >> c >> k;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >> board[i][j];

    int row = 3, col = 3, sec = 0;

    while (true)
    {
        if (board[r - 1][c - 1] == k) break;
        if (sec == 100) { sec = -1; break; }

        int first = max(row, col);
        int second = min(row, col);
        vector<int> l(first);

        for (int i = 0; i < first; i++)
        {
            fill(freq, freq + MAX, 0);
            vector<pair<int, int>> sf;

            for (int j = 0; j < second; j++)
            {
                int val = (row >= col) ? board[i][j] : board[j][i];
                if (val) freq[val]++;
            }

            for (int j = 1; j < MAX; j++)
                if (freq[j]) sf.push_back({ j, freq[j] });

            sort(sf.begin(), sf.end(), cmp);

            for (int j = 0; j < sf.size() && j < 50; j++)
            {
                if (row >= col)
                {
                    board[i][j * 2] = sf[j].first;
                    board[i][j * 2 + 1] = sf[j].second;
                }
                else
                {
                    board[j * 2][i] = sf[j].first;
                    board[j * 2 + 1][i] = sf[j].second;
                }
            }

            l[i] = (sf.size() >= 50) ? 100 : sf.size() * 2;
        }

        second = *max_element(l.begin(), l.end());

        for (int i = 0; i < first; i++)
        {
            for (int j = l[i]; j < second; j++)
            {
                if (row >= col) board[i][j] = 0;
                else board[j][i] = 0;
            }
        }

        if (row >= col) col = second;
        else row = second;

        sec++;
    }

    cout << sec;
}
