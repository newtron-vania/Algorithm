#include <bits/stdc++.h>

using namespace std;

int n;
int value[100000];

void input()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        value[i] = a;
    }
}

int binary_search(vector<int> arr, int val)
{
    int left = 0, right = arr.size() - 1;
    while(left <= right)
    {
        int mid = (left + right) / 2;
        if(arr[mid] < val)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    
    return left;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    input();
    
    vector<int> result_arr;
    for(int i = 0; i < n; i++)
    {
        int val = value[i];
        if(result_arr.size() == 0 || result_arr.back() < val)
        {
            result_arr.push_back(val);
            continue;
        }
        
        int idx = binary_search(result_arr, val);
        result_arr[idx] = val;
        
    }
    
    cout << n - result_arr.size() << endl;
    
}