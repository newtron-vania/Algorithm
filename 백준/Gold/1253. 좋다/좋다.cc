#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int n, ans = 0;
    cin >> n;
    vector<int> arr(n, 0);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    sort(arr.begin(), arr.end());
    // 순서대로 확인하기
    for(int i = 0; i < n; i++)
    {
       int left = 0, right = n-1;
        
        while(left < right)
        {
            if(left == i){left++; continue;}
            if(right == i){right--; continue;}
            if(arr[left] + arr[right] > arr[i]) right--;
            else if(arr[left] + arr[right] < arr[i]) left++;
            else{ ans++; break;}
        }
    }
    cout << ans << endl;
}