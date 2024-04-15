#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (true) {
        int command;
        cin >> command;
        if (command == 0) break;

        vector<long long> height;
        for (int i = 0; i < command; i++) {
            long long h;
            cin >> h;
            height.push_back(h);
        }
        height.push_back(0); // 높이 목록에 0을 추가합니다.

        stack<pair<int, long long>> stk;
        stk.push({0, 0}); // 초기 인덱스와 높이를 스택에 넣습니다.
        long long ans = 0;

        for (int idx = 1; idx <= height.size(); idx++) {
            int val = height[idx - 1];
            while (!stk.empty() && stk.top().second > val) {
                auto [i, v] = stk.top();
                stk.pop();
                if (!stk.empty() && stk.top().second == v) {
                    stk.pop();
                }
                ans = max(ans, (idx - 1 - stk.top().first) * v);
            }
            stk.push({idx, val});
        }
        cout << ans << endl;
    }
    return 0;
}