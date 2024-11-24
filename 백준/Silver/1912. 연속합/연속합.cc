#include  <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> vec;
    
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        vec.push_back(a);
    }
    
    vector<int> dp(n, 0);
    dp[0] = vec[0];
    for(int i = 1; i < n; i++)
    {
        dp[i] = max(dp[i-1] + vec[i], vec[i]);
    }
    
    int result = *max_element(dp.begin(), dp.end());
    
    cout << result;
    
}