#include <bits/stdc++.h>
using namespace std;

struct Box
{
    int from, to, num;
};

int main()
{
    int N, C, M;
    scanf("%d %d", &N, &C);
    scanf("%d", &M);

    vector<Box> boxes(M);
    for (int i = 0; i < M; i++)
    {
        scanf("%d %d %d", &boxes[i].from, &boxes[i].to, &boxes[i].num);
    }

    sort(boxes.begin(), boxes.end(), [](const Box &a, const Box &b)
    {
        if (a.to == b.to) return a.from < b.from;
        return a.to < b.to;
    });

    vector<int> remain(N + 1, C);
    int ans = 0;

    for (auto &b : boxes)
    {
        int mn = INT_MAX;
        for (int i = b.from; i < b.to; i++)
        {
            mn = min(mn, remain[i]);
        }

        int take = min(mn, b.num);
        if (take <= 0) continue;

        for (int i = b.from; i < b.to; i++)
        {
            remain[i] -= take;
        }
        ans += take;
    }

    printf("%d\n", ans);
    return 0;
}
