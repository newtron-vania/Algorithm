#include <bits/stdc++.h>

using namespace std;

bool binary_search(const vector<string>& s, const string& query)
{
    int left = 0, right = s.size() - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        const string& target = s[mid];

        int cmp = target.compare(0, query.size(), query);

        if (cmp == 0)
        {
            return true;
        }
        else if (target < query)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return false;
}

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

        if (binary_search(s, query))
        {
            count++;
        }
    }

    cout << count << '\n';
    return 0;
}
