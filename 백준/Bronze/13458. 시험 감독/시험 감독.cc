#include <bits/stdc++.h>

using namespace std;

int arr[1'000'001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, b, c;
    long long result = 0;
    
    cin >> n;
    
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr[i] = x;
    }
    
    cin >> b >> c;
    
    for(int i = 0; i < n; i++)
    {
        result++;
        int remaining = arr[i] - b;
        if(remaining > 0)
        {
            result += (remaining + c - 1) / c;
        }
    }
    
    
    cout << result << endl;
}