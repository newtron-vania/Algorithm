#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    long long m;
    cin >> n >> m;
    
    vector<int> vec(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }
    
    int left = 0, right = 0;
    long long sum = 0;
    int cnt = 0;

    while (right <= n)
    {
        if (sum < m)
        {
            if (right == n) break;
            sum += vec[right++];
        }
        else
        {
            sum -= vec[left++];
        }

        if (sum == m)
        {
            cnt++;
        }

        if (left > right)
        {
            right = left;
        }
    }

    cout << cnt << endl;
    return 0;
}
