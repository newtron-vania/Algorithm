#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<vector<int>> graph(n + 1);
        vector<int> inDegree(n + 1, 0);

        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        vector<int> topologic_node;
        for (int i = n - 1; i >= 0; --i) {
            int team = arr[i];
            graph[team] = topologic_node;
            topologic_node.push_back(team);
            inDegree[team] = i;
        }

        int m;
        cin >> m;
        for (int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
            auto it = find(graph[b].begin(), graph[b].end(), a);
            if (it != graph[b].end()) {
                swap(a, b);
            }
            graph[a].erase(remove(graph[a].begin(), graph[a].end(), b), graph[a].end());
            inDegree[b]--;
            graph[b].push_back(a);
            inDegree[a]++;
        }

        queue<int> queue;
        for (int i = 1; i <= n; ++i) {
            if (inDegree[i] == 0) {
                queue.push(i);
            }
        }
        vector<int> answer;
        bool isPossible = false;
        if (queue.size() == 1) {
            isPossible = true;
        }

        while (!queue.empty()) {
            if (queue.size() != 1) {
                isPossible = false;
                break;
            }
            int now = queue.front();
            queue.pop();
            answer.push_back(now);
            while (!graph[now].empty()) {
                int next = graph[now].back();
                graph[now].pop_back();
                inDegree[next]--;
                if (inDegree[next] == 0) {
                    queue.push(next);
                } else if (inDegree[next] < 0) {
                    isPossible = false;
                    break;
                }
            }
        }
        if (!isPossible || answer.size() < n) {
            cout << "IMPOSSIBLE\n";
        } else {
            for (int i = 0; i < answer.size(); ++i) {
                cout << answer[i] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
