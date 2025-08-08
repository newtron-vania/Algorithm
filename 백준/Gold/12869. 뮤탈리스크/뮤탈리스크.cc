#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int dp[61][61][61];

struct State
{
    int cost, a, b, c;
    bool operator<(const State& o) const
    {
        return cost > o.cost;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int scv[3] = {0, 0, 0};
    for (int i = 0; i < n; i++)
    {
        cin >> scv[i];
    }

    fill(&dp[0][0][0], &dp[60][60][61], INF);

    priority_queue<State> pq;
    pq.push({0, scv[0], scv[1], scv[2]});

    // 가능한 공격 데미지 조합
    int da[6] = {9, 9, 3, 3, 1, 1};
    int db[6] = {3, 1, 9, 1, 9, 3};
    int dc[6] = {1, 3, 1, 9, 3, 9};

    while (!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();

        int cost = cur.cost;
        int a = cur.a;
        int b = cur.b;
        int c = cur.c;

        if (cost >= dp[a][b][c])
        {
            continue;
        }
        
        dp[a][b][c] = cost;

        if (a == 0 && b == 0 && c == 0)
        {
            cout << cost << "\n";
            return 0;
        }

        for (int m = 0; m < 6; m++)
        {
            int na = max(0, a - da[m]);
            int nb = max(0, b - db[m]);
            int nc = max(0, c - dc[m]);

            int dpc = dp[na][nb][nc];
            if (dpc > cost + 1)
            {
                dpc = cost + 1;
                pq.push({dpc, na, nb, nc});
            }
        }
    }

    return 0;
}