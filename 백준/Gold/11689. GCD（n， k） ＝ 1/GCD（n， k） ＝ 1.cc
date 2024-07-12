#include <bits/stdc++.h>
int main()
{
    long long n;
    scanf("%lld", &n);
    long long euler = n;
    for (long long p = 2; p*p <= n; p++)
    {
        if (n % p == 0) euler = euler/p *(p - 1);
        while (n % p == 0) n = n/p;
    }
    
    printf("%lld", n == 1 ? euler : euler/n *(n - 1));
}