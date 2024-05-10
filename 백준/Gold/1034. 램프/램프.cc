#include <bits/stdc++.h>

using namespace std;

int main()
{
    int h, w;
    int ans = -1;
    string arr[50];

    cin >> h >> w;

    for (int y = 0; y < h; y++)
    {
        cin >> arr[y];
    }

    int k;
    cin >> k;

    for (int i = 0; i < h; i++)
    {
        int zeroCount = 0;
        for (int h = 0; h < w; h++)
        {
            if (arr[i][h] == '0')
            {
                zeroCount++;
            }
        }
        int sum = 0;
        if (zeroCount <= k && zeroCount % 2 == k % 2)
        {
            for (int y = 0; y < h; y++)
            {
                if (arr[i] == arr[y])
                {
                    sum++;
                }
            }
        }
        ans = max(sum, ans);
    }
    
    cout << ans;
    return 0;
}