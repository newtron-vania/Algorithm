#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int start = 1, end = k, ans = 0;
    while (start <= end) 
    {
        int mid = (start + end) / 2;
        int temp = 0;
        for (int i = 1; i <= n; i++) 
        {
            temp += min(mid / i, n);
        }
        if (temp < k) 
        {
            start = mid + 1;
        } 
        else 
        {
            ans = mid;
            end = mid - 1;
        }
    }

    cout << ans << endl;

    return 0;
}