#include <bits/stdc++.h>

using namespace std;

int f[200001][20];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int m;
    cin >> m;

    for (int i = 1; i <= m; ++i)
    {
        cin >> f[i][0];
    }
    
    // 2진수 이동 값을 배열에 채운다.
    for (int j = 1; j < 20; j++)
    {
        for (int i = 1; i <= m; i++)
        {
            f[i][j] = f[f[i][j - 1]][j - 1];
        }
    }       

    int q;
    cin >> q;
    while (q--) 
    {
        int n, x;
        cin >> n >> x;

        for (int i = 0; 0 < n; i++)
        {
            if (n & 1)
            {
                x = f[x][i];
            }
            n >>= 1;
        }

        cout << x << '\n';
    }
}
