#include <bits/stdc++.h>
using namespace std;

int N;
pair<int, int> point[21];
bool selected[21];
double ans;

void dfs(int idx, int cnt)
{
    if (cnt == N / 2)
    {
        long long sx = 0, sy = 0;
        for (int i = 0; i < N; i++)
        {
            if (selected[i])
            {
                sx += point[i].first;
                sy += point[i].second;
            }
            else
            {
                sx -= point[i].first;
                sy -= point[i].second;
            }
        }
        double len = sqrt((long double)(sx * sx + sy * sy));
        if (len < ans) ans = len;
        return;
    }
    if (idx == N) return;

    selected[idx] = true;
    dfs(idx + 1, cnt + 1);

    selected[idx] = false;
    dfs(idx + 1, cnt);
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &N);
        for (int i = 0; i < N; i++)
        {
            scanf("%d %d", &point[i].first, &point[i].second);
        }

        ans = 1e18;
        dfs(0, 0);

        printf("%.12f\n", ans);
    }
    return 0;
}
