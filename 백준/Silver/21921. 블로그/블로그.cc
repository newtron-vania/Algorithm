#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    
    int* val = new int[n](); 
    
    for(int i = 0; i < n; i++)
    {
        int cnt;
        cin >> cnt;
        val[i] = cnt;
    }
    
    int sum_max = 0;
    int sum = 0;
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        sum += val[i];
        if(i >= x) sum -= val[i - x]; 
        if(sum_max == sum) cnt++;
        if(sum_max < sum) 
        {
            cnt = 1;
            sum_max = sum;
        }
    }
    
    if(sum_max > 0)
    {
        cout << sum_max << endl;
        cout << cnt << endl;
    }
    else
    {
        cout << "SAD" << endl;
    }
}