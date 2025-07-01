#include <bits/stdc++.h>

using namespace std;

const int length = 18;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    while(T--)
    {
        long long n;
        cin >> n;
        vector<long long> values;
        int count = 0;
        while (n > 0)
        {
            values.push_back(n);
            n >>= 1;
            count++;
        }

        for (int i = count; i > 0; i--)
        {
            int left = i;
            long long right_val = values[count - i] - ((1LL << (i - 1)) - 1);

            // %0*lld → 0으로 채운 length자리 숫자
            printf("%d%0*lld\n", left, length, right_val);
        }
    }
}