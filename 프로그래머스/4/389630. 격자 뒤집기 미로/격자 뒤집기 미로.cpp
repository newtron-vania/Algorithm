#include <bits/stdc++.h>
using namespace std;

auto calc = [](auto a, auto b, int k) {
    const int n = a.size();
    const int m = a[0].size();
    vector dp{ 0, -(1 << 30) };
    for (int j = 0; j < m; j++) {
        int sa = 0, mn_a = 1 << 30;
        int sb = 0, mn_b = 1 << 30;
        for (int i = 0; i < n; i++) {
            sa += a[i][j];
            sb += b[i][j];
            if (i + j & 1) {
                mn_a = min(mn_a, a[i][j]);
                mn_b = min(mn_b, b[i][j]);
            }
        }
        vector ndp(2, 0);
        ndp[0] = dp[0] + max(sa, sb - k);
        ndp[1] = max(
            dp[0] + max(sa - mn_a, sb - mn_b - k),
            dp[1] + max(sa, sb - k)
        );
        dp.swap(ndp);
    }
    return dp[~n & 1 && ~m & 1];
};

int solution(vector<vector<int>> a, vector<vector<int>> b, int k) {
    const int n = a.size();
    const int m = a[0].size();
    int res = -(1 << 30);
    for (int s = 0; s < 1 << n; s++) {
        for (int i = 0; i < n; i++) {
            if (~s >> i & 1) continue;
            swap(a[i], b[i]);
        }
        int x = calc(a, b, k);
        int y = __builtin_popcount(s);
        res = max(res, x - k * y);
        for (int i = 0; i < n; i++) {
            if (~s >> i & 1) continue;
            swap(a[i], b[i]);
        }
    }
    return res;
}