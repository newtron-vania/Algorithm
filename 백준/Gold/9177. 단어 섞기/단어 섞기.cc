#include <bits/stdc++.h>

using namespace std;

vector<tuple<string, string, string>> dataSets;

void input()
{
    int n;
    cin >> n;
    
    while(n-- > 0)
    {
        string a, b, c;
        cin >> a >> b >> c;
        dataSets.emplace_back(a, b, c);
    }
}

void output(int caseNum, bool result)
{
    cout << "Data set " << caseNum << ": " << (result ? "yes" : "no") << "\n";
}

bool dp[201][201];
bool visited[201][201];

string a_, b_, r_;

bool dfs(int a_idx, int b_idx)
{
    int depth = a_idx + b_idx;
    if (depth == (int)r_.size()) return true;

    if (visited[a_idx][b_idx]) return dp[a_idx][b_idx];
    visited[a_idx][b_idx] = true;

    bool res = false;
    if (a_idx < (int)a_.size() && a_[a_idx] == r_[depth])
        res |= dfs(a_idx + 1, b_idx);

    if (!res && b_idx < (int)b_.size() && b_[b_idx] == r_[depth])
        res |= dfs(a_idx, b_idx + 1);

    return dp[a_idx][b_idx] = res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();

    int caseNum = 1;
    for (auto& [a, b, r] : dataSets)
    {
        a_ = a; b_ = b; r_ = r;
        memset(dp, 0, sizeof(dp));
        memset(visited, 0, sizeof(visited));

        bool result = dfs(0, 0);
        output(caseNum++, result);
    }

    return 0;
}