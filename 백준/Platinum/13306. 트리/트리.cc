#include <bits/stdc++.h>

using namespace std;

const int inf = 200001;
stack<pair<int, int>> r;
stack<string> ans;
int n, q, p[inf], e[inf];

int find(int x) {
    return p[x] == x ? x : p[x] = find(p[x]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    e[1] = p[1] = 1;
    for (int i = 2; i <= n; i++) {
        cin >> e[i];
        p[i] = i;
    }
    for (int i = 0; i < q + n - 1; i++) {
        int a, b, c; cin >> a >> b;
        if (a) {
            cin >> c;
            r.push({b, c});
        }
        else {
            r.push({b, 0});
        }
    }
    while (!r.empty()) {
        auto k = r.top();
        r.pop();
        if (k.second)
            ans.push(find(k.first) == find(k.second) ? "YES" : "NO");
        else
            p[k.first] = e[k.first];
    }
    while (!ans.empty()) {
        cout << ans.top() << '\n';
        ans.pop();
    }
    return 0;
}