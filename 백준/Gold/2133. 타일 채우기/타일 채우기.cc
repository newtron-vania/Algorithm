#include <bits/stdc++.h>
using namespace std;

vector<int> dp(31, 0);

int DFS(int n)
{
    if (n % 2 == 1)
    {
        return 0;
    }
    if (n <= 2)
    {
        return dp[n];
    }
    if (dp[n] != 0)
    {
        return dp[n];
    }

    dp[n] = 3 * DFS(n - 2);
    for (int i = n - 4; i >= 0; i -= 2)
    {
        dp[n] += 2 * DFS(i);
    }

    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    dp[0] = 1;
    dp[2] = 3;
    cout << DFS(n);
    return 0;
}
