#include <iostream>
using namespace std;
#define MAX 1000000

int arr[MAX + 1]{0,};

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    for (int i = 2; i <= MAX; i++)
    {
        arr[i] = i;
    }

    for (int i = 2; i * i <= MAX; i++)
    {
        if (arr[i] == 0)
        {
            continue;
        }
        for (int j = i * i; j <= MAX; j += i)
        {
            arr[j] = 0;
        }
    }

    int t;
    cin >> t;
    
    while (t--)
    {
        int n;
        cin >> n;

        int cnt(0);
        for (int i = 2; i < n; i++)
        {
            if (arr[n - i] + arr[i] == n)
            {
                cnt++;
                if (n - i == i)
                {
                    cnt++;
                }
            }
        }
        cout << cnt / 2 << '\n';
    }

    return 0;
}