#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int k;
    cin >> k;

    int c;
    cin >> c;

    for (int i = 0; i < c; i++)
    {
        int m;
        int n;
        cin >> m >> n;

        if (m - n == 0)
        {
            cout << 1 << '\n';
            continue;
        }

        int remain_games = k - max(m, n);
        int diff = abs(m - n);

        if (m > n)
        {
            if (diff - remain_games <= 2)
            {
                cout << 1 << '\n';
                continue;
            }

            cout << 0 << '\n';
            continue;
        }

        if (diff - remain_games <= 1)
        {
            cout << 1 << '\n';
            continue;
        }

        cout << 0 << '\n';
    }

    return 0;
}
