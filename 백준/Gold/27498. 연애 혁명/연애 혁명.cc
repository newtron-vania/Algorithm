#include <bits/stdc++.h>

using namespace std;

struct DSU
{
    int parent[200001];
    int rnk[200001];

    void init(int n)
    {
        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
            rnk[i] = 0;
        }
    }

    int find(int x)
    {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    bool unite(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a == b) return false;

        if (rnk[a] < rnk[b]) swap(a, b);
        parent[b] = a;
        if (rnk[a] == rnk[b]) rnk[a]++;
        return true;
    }
};

struct Edge
{
    int u, v;
    int w;
};

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);

    DSU dsu;
    dsu.init(N);

    vector<Edge> edges;
    long long sum_d0 = 0;

    for (int i = 0; i < M; i++)
    {
        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b, &c, &d);

        if (d == 1)
        {
            // 이미 성사된 관계는 반드시 포함 -> 미리 union만 수행
            dsu.unite(a, b);
        }
        else
        {
            // 이루어지지 않은 관계는 후보로 저장하고 총합에 포함
            edges.push_back({a, b, c});
            sum_d0 += c;
        }
    }

    // d=0 간선들을 가중치 내림차순(큰 것부터) 정렬하여
    // 최대 스패닝 트리 형태로 가능한 많은 가중치를 유지한다.
    sort(edges.begin(), edges.end(), [](const Edge &A, const Edge &B)
    {
        return A.w > B.w;
    });

    long long kept = 0;
    for (auto &e : edges)
    {
        if (dsu.unite(e.u, e.v))
            kept += e.w;
    }

    // 포기하는 애정도의 합 = (d=0 간선들의 전체 합) - (유지된 d=0 간선들의 합)
    long long answer = sum_d0 - kept;
    printf("%lld\n", answer);

    return 0;
}
