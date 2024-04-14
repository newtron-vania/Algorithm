#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int bfs(int n, int m, vector<vector<int>>& graph) {
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    queue<pair<int, int>> q;
    q.push({0, 0});

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (x == n - 1 && y == m - 1) {
            return graph[x][y];
        }

        for (int i = 0; i < 4; i++) {
            int hx = x + dx[i];
            int hy = y + dy[i];

            if (hx < 0 || hy < 0 || hx >= n || hy >= m) {
                continue;
            }
            if (graph[hx][hy] == 0) {
                continue;
            }
            if (graph[hx][hy] == 1) {
                q.push({hx, hy});
                graph[hx][hy] = graph[x][y] + 1;
            }
        }
    }

    return -1;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%1d", &graph[i][j]);
        }
    }

    cout << bfs(n, m, graph) << endl;

    return 0;
}
