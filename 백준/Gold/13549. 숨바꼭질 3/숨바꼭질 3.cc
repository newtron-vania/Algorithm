#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    if (n >= m)
    {
        cout << n - m << '\n';
        return 0;
    }

    int max_pos = m * 2 + 1;
    vector<int> dp(max_pos, INF);
    dp[n] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, n});

    while (!pq.empty()) 
    {
        auto [wei, pos] = pq.top(); 
        pq.pop();

        if (pos == m) 
        {
            cout << wei << '\n';
            return 0;
        }

        for (int next : {pos * 2, pos - 1, pos + 1})
        {
            if (next < 0 || next >= max_pos) continue;

            int cost = (next == pos * 2) ? wei : wei + 1;

            if (dp[next] > cost) 
            {
                dp[next] = cost;
                pq.push({cost, next});
            }
        }
    }

    return 0;
}
