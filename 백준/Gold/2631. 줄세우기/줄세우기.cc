#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    
    int arr[201];
    
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    vector<int> sorted;
    for(int i = 0; i < n; i++)
    {
        int val = arr[i];
        if(sorted.size() == 0 || sorted.back() <= val)
        {
            sorted.push_back(val);
        }
        else
        {
            int idx = lower_bound(sorted.begin(), sorted.end(), val) - sorted.begin();
            sorted[idx] = val; 
        }
    }
    
    cout << n - sorted.size();
}