#include <bits/stdc++.h>

using namespace std;
const int MAX_COUNT = 2001;
int n;
int values[MAX_COUNT]; 
vector<pair<int, int>> arr;

void input()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        values[i] = a;
    }
}


int binary_search(vector<int>& sorted, int num)
{
    int left = 0;
    int right = sorted.size() - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (sorted[mid] < num)
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
    
    vector<int> sorted;
    for (int i = 0; i < n; i++) 
    {
        int val = values[i];
        int idx = binary_search(sorted, val);

        if (idx == sorted.size()) 
        {
            sorted.push_back(val);
        } else 
        {
            sorted[idx] = val;
        }
        arr.push_back({val, idx});
    }
    
    int idx = sorted.size() - 1;
    vector<int> result(sorted.size());
    for(int i = arr.size() - 1; i >= 0 && idx >= 0; i--)
    {
        if(arr[i].second == idx)
        {
            result[idx] = arr[i].first;
            idx--;
        }
    }
    
    
    cout << result.size() << endl;
    
    for(int r : result)
    {
        cout << r << " ";
    }
}