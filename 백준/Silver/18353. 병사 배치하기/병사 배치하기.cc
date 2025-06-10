#include <bits/stdc++.h>

using namespace std;

int n;
int arr[2000] = {0,};

void input()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        arr[i] = a;
    }
}


int binary_search(vector<int> sorted, int num)
{
    int left = 0;
    int right = sorted.size() - 1;
    while (left < right)
    {
        int mid = (left + right) / 2;

        if (sorted[mid] > num)
        {
            left = mid + 1;
        }
        else  
        {
            right = mid;
        }
    }
    
    return left;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    
    vector<int> sorted;
    for(int i = 0; i < n; i++)
    {
        if(sorted.size() == 0 || sorted.back() > arr[i])
        {
            sorted.push_back(arr[i]);
            continue;
        }
        else if(sorted.back() == arr[i]) continue;
        
        int idx = binary_search(sorted, arr[i]);
        sorted[idx] = arr[i];
    }
    
    int result = sorted.size();
    cout << n - result << endl;
}