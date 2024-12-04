#include <bits/stdc++.h>
using namespace std;

int n, m, ans = 11;
vector<vector<int>> beginning, target;

void toggleRow(int r) {
    for (int j = 0; j < m; j++) {
        beginning[r][j] = !beginning[r][j];
    }
}

int checkColumn(int c) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (beginning[i][c] == target[i][c]) {
            cnt++;
        }
    }

    if (cnt == 0) return 1;
    if (cnt == n) return 0;
    return -1;
}

void dfs(int r, int cnt) {
    if (r == n) {
        int flag = 1;
        for (int j = 0; j < m; j++) {
            int ret = checkColumn(j);
            if (ret == -1) {
                flag = 0;
                break;
            }
            cnt += ret;
        }
        if (flag) {
            ans = min(ans, cnt);
        }
        return;
    }
    dfs(r + 1, cnt);
    toggleRow(r);
    dfs(r + 1, cnt + 1);
    toggleRow(r);
}

int solution(vector<vector<int>> _beginning, vector<vector<int>> _target) {
    beginning = _beginning;
    target = _target;
    n = beginning.size();
    m = beginning[0].size();
    dfs(0, 0);
    if (ans == 11) return -1;
    return ans;
}
