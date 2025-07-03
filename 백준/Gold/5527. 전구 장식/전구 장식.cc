#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    vector<int> lights(n);

    for (int i = 0; i < n; i++)
    {
        cin >> lights[i];
    }

    vector<int> groups;
    
    int cnt = 1;
    for (int i = 1; i < n; i++)
    {
        if (lights[i] != lights[i - 1]) cnt++;
        else
        {
            groups.push_back(cnt);
            cnt = 1;
        }
    }

    if(cnt != 0) groups.push_back(cnt);

    int ans = 0;
    for (int i = 0; i < groups.size(); i++)
    {
        int cnt = groups[i];
        if (i != 0) cnt += groups[i - 1];
        if (i != groups.size()-1) cnt += groups[i + 1];

        ans = max(ans, cnt);
    }

    cout << ans;

    return 0;
}