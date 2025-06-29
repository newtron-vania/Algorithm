#include <bits/stdc++.h>

using namespace std;

bool binary_search(const vector<string>& s, const string& query)
{
    int left = 0, right = s.size();
    while(left < right)
    {
        int mid = (left + right) / 2;
        if(s[mid] < query)
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }
    
    return left < s.size() && s[left].substr(0, query.size()) == query;
}

bool binary_search_prefix(vector<string>& v, const string& prefix)
{
    int left = 0, right = v.size();

    while (left < right)
    {
        int mid = (left + right) / 2;
        if (v[mid] < prefix)
            left = mid + 1;
        else
            right = mid;
    }

    return left < v.size() && v[left].substr(0, prefix.size()) == prefix;
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

        if(binary_search(s, query))
        {
            count++;
        }
    }

    cout << count << '\n';
    return 0;
}
