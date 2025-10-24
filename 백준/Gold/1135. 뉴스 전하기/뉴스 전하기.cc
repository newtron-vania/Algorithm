#include <bits/stdc++.h>

using namespace std;

vector<int> tree[51];

int dfs(int node)
{
    vector<int> times;

    for (int next : tree[node])
    {
        times.push_back(dfs(next));
    }

    sort(times.begin(), times.end(), greater<int>());

    int result = 0;
    for (int i = 0; i < (int)times.size(); i++)
    {
        result = max(result, times[i] + i + 1);
    }

    return result;
}

int main()
{
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        int p;
        scanf("%d", &p);
        if (p != -1)
        {
            tree[p].push_back(i);
        }
    }

    printf("%d\n", dfs(0));
    return 0;
}