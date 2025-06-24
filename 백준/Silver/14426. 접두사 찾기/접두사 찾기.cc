#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<string> s(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> s[i];
    }

    sort(s.begin(), s.end());

    int count = 0;
    for (int i = 0; i < m; ++i)
    {
        string query;
        cin >> query;

        auto it = lower_bound(s.begin(), s.end(), query);
        if (it != s.end() && it->compare(0, query.size(), query) == 0)
        {
            count++;
        }
    }

    cout << count << '\n';
    return 0;
}
