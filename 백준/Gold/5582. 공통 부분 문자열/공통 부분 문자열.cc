#include <bits/stdc++.h>

using namespace std;

string s1, s2;
vector<vector<int>> dp;
int answer;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s1 >> s2;
    dp = vector<vector<int>>(s1.size() + 1, vector<int>(s2.size() + 1));

    for (int i = 0; i < s1.size(); ++i)
    {
        for (int j = 0; j < s2.size(); ++j)
        {
            if (s1[i] == s2[j])
            {
                dp[i + 1][j + 1] = dp[i][j] + 1;
                answer = max(answer, dp[i + 1][j + 1]);
            }
        }
    }
    cout << answer << endl;
    return 0;
}