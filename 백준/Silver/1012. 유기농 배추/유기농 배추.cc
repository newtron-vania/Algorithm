#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <iostream>

using namespace std;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
void BFS(bool graph[51][51], bool visited[51][51], int n, int m, int x, int y) {
    visited[x][y] = true;
    queue<vector<int>> q;
    q.push({ x, y });

    while (!q.empty()) {
        vector<int> node = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int mx = node[0] + dx[i];
            int my = node[1] + dy[i];
            if (mx < 0 || my < 0 || mx >= n || my >= m)
                continue;
            if (!graph[mx][my] || visited[mx][my])
                continue;
            visited[mx][my] = true;
            q.push({ mx, my });
        }
    }
}

int main() {
    int T;
    cin >> T;
    while (T-- > 0) {
        int n, m, c;
        cin >> n >> m >> c;
        bool graph[51][51] = { false, };
        bool visited[51][51] = { false, };

        int answer = 0;
        while (c-- > 0) {
            int a, b;
            cin >> a >> b;
            graph[a][b] = true;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (graph[i][j] && !visited[i][j]) {
                    answer += 1;
                    BFS(graph, visited, n, m, i, j);
                }
            }
        }

        cout << answer << endl;
    }

    return 0;
}