#include <bits/stdc++.h>
using namespace std;

int a[1001], b[1001];
int diffv[1002];

int main()
{
    int N;
    scanf("%d", &N);

    for (int i = 1; i <= N; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= N; i++) scanf("%d", &b[i]);

    diffv[0] = 0;
    
    for (int i = 1; i <= N; i++) diffv[i] = b[i] - a[i];
    
    diffv[N + 1] = 0;

    int ans = 0;
    for (int i = 1; i <= N + 1; i++)
    {
        int inc = diffv[i] - diffv[i - 1];
        if (inc > 0) ans += inc;
    }

    printf("%d\n", ans);
}
