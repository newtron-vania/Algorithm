#include <bits/stdc++.h>
using namespace std;

int n;
int h[51];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        int cnt = 0;

        // 오른쪽 탐색
        double maxSlope = -1e9;
        for (int j = i + 1; j < n; j++)
        {
            double slope = (double)(h[j] - h[i]) / (j - i);
            if (slope > maxSlope)
            {
                maxSlope = slope;
                cnt++;
            }
        }

        // 왼쪽 탐색
        maxSlope = 1e9;
        for (int j = i - 1; j >= 0; j--)
        {
            double slope = (double)(h[j] - h[i]) / (j - i);
            if (slope < maxSlope)
            {
                maxSlope = slope;
                cnt++;
            }
        }

        ans = max(ans, cnt);
    }

    cout << ans << '\n';
    return 0;
}
