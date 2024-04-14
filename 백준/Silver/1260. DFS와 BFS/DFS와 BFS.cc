#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void dfs(int v, int n, vector<int>& visited_dfs, vector<vector<int>>& matrix) {
    visited_dfs[v] = 1;
    cout << v << " ";
    for (int i = 1; i <= n; i++) {
        if (matrix[v][i] == 1 && visited_dfs[i] == 0) {
            dfs(i, n, visited_dfs, matrix);
        }
    }
}

void bfs(int v, int n, vector<int>& visited_bfs, vector<vector<int>>& matrix) {
    queue<int> q;
    q.push(v);
    visited_bfs[v] = 1;
    while (!q.empty()) {
        v = q.front();
        q.pop();
        cout << v << " ";
        for (int i = 1; i <= n; i++) {
            if (matrix[v][i] == 1 && visited_bfs[i] == 0) {
                q.push(i);
                visited_bfs[i] = 1;
            }
        }
    }
}

int main() {
    int n, m, v;
    cin >> n >> m >> v;
    vector<vector<int>> matrix(n + 1, vector<int>(n + 1, 0));
    vector<int> visited_dfs(n + 1, 0);
    vector<int> visited_bfs(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        matrix[a][b] = matrix[b][a] = 1;
    }

    dfs(v, n, visited_dfs, matrix);
    cout << endl;
    bfs(v, n, visited_bfs, matrix);

    return 0;
}
