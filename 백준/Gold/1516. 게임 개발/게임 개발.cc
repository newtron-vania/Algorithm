#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

const int MAX = 501;
using namespace std;

int n;
vector<int> edge[MAX];
int inDegree[MAX];
int cost[MAX];
int dp[MAX];

void TopologicalSort() {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
            dp[i] = cost[i];
        }
    }


    while (!q.empty()) {
        int cur_node = q.front();
        q.pop();
        for (int i = 0; i < edge[cur_node].size(); i++) {
            int next = edge[cur_node][i];
            if (--inDegree[next] == 0) {
                q.push(next);

            }
            dp[next] = max(dp[next], cost[next] + dp[cur_node]);
        }

    }
    for (int i = 1; i <= n; i++)
        cout << dp[i] << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> cost[i];
        int input;
        cin >> input;
        while (input != -1) {
            inDegree[i]++;
            edge[input].push_back(i);
            cin >> input;
        }
    }
    TopologicalSort();
    return 0;
}