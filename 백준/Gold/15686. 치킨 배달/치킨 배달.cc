#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int n, m;
int result = INF;
vector<vector<int>> houseVec;
vector<vector<int>> chickVec;

void Dfs(int depth, int idx, vector<vector<int>>& selected)
{
    if (depth == m)
    {
        int totalDist = 0;
        for (auto& h : houseVec)
        {
            int dist = INF;
            for (auto& c : selected)
            {
                dist = min(dist, abs(h[0] - c[0]) + abs(h[1] - c[1]));
            }
            totalDist += dist;
        }
        result = min(result, totalDist);
        return;
    }

    for (int i = idx; i < chickVec.size(); i++)
    {
        selected.push_back(chickVec[i]);
        Dfs(depth + 1, i + 1, selected);
        selected.pop_back();
    }
}

int main()
{
    cin >> n >> m;
    vector<vector<string>> maps(n, vector<string>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> maps[i][j];
            if (maps[i][j] == "1")
            {
                houseVec.push_back({i, j});
            }
            else if (maps[i][j] == "2")
            {
                chickVec.push_back({i, j});
            }
        }
    }

    vector<vector<int>> selected;
    Dfs(0, 0, selected);

    cout << result << endl;
    return 0;
}