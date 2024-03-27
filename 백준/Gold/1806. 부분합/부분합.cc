#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int  n, x;
    cin >> n >> x;
    vector<int> arr(n, 0);
    int answer = n + 1;
    
    for (int i = 0; i < n; i++) 
    {
        cin >> arr[i];
    }
    
    int left = 0, right = 0, sum = 0;
    
    while(right <= n)
    {
        if(sum >= x)
        {
            answer = min(answer, right - left);
            sum -= arr[left];
            left++;
        }
        else
        {
            if(right >= n)
                break;
            sum += arr[right];
            right++;
        }
    }

    cout << (answer > n ? 0 : answer) << endl;
    return 0;
}