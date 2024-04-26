#include <bits/stdc++.h>

using namespace std;

void hanoi(int n, int a, int b, int c) {
    if (n <= 1) {
        cout << a << " " << c << "\n";
    } else {
        hanoi(n - 1, a, c, b);
        cout << a << " " << c << "\n";
        hanoi(n - 1, b, a, c);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    cout << (1 << n) - 1 << "\n"; // 2^n - 1을 계산합니다.
    hanoi(n, 1, 2, 3);

    return 0;
}