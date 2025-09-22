#include <bits/stdc++.h>

using namespace std;

int main()
{
    int target, n, m;
    scanf("%d", &target);
    scanf("%d %d", &n, &m);

    vector<int> A(n), B(m);
    for (int i = 0; i < n; i++) scanf("%d", &A[i]);
    for (int i = 0; i < m; i++) scanf("%d", &B[i]);

    vector<int> prefixA(2 * n + 1, 0), prefixB(2 * m + 1, 0);

    for (int i = 1; i <= 2 * n; i++)
    {
        prefixA[i] = prefixA[i - 1] + A[(i - 1) % n];
    }
        
    for (int i = 1; i <= 2 * m; i++)
    {
        prefixB[i] = prefixB[i - 1] + B[(i - 1) % m];
    }
        

    map<int, int> sumA, sumB;

    // A 부분합
    for (int len = 1; len < n; len++) 
    {
        for (int i = 0; i + len <= 2 * n; i++) 
        {
            if (i + len <= n || i < n) {
                int val = prefixA[i + len] - prefixA[i];
                sumA[val]++;
            }
        }
    }
    sumA[prefixA[n]]++;

    // B 부분합
    for (int len = 1; len < m; len++) 
    {
        for (int i = 0; i + len <= 2 * m; i++) 
        {
            if (i + len <= m || i < m) 
            {
                int val = prefixB[i + len] - prefixB[i];
                sumB[val]++;
            }
        }
    }
    sumB[prefixB[m]]++;

    int ans = 0;

    ans += sumA[target];
    ans += sumB[target];

    for (auto &p : sumA)
    {
        int need = target - p.first;
        if (sumB.count(need))
            ans += p.second * sumB[need];
    }

    printf("%d\n", ans);
    return 0;
}
