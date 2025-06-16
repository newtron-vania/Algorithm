#include <bits/stdc++.h>
#define SIZE 2010
using namespace std;

typedef long long ll;
typedef struct Point 
{
    ll distance;
    int start, end;
} point;
typedef pair<ll, ll> pi;

struct compare
{
    bool operator() (const point &a, const point &b)
    {
        return a.distance > b.distance;
    }
};

int N, C;
vector<pi> V;
int parent[SIZE];
priority_queue<point, vector<point>, compare> pq;

int get_parent(int x)
{
    if (parent[x] == x)
    {
        return parent[x];
    }
    else
    {
        return parent[x] = get_parent(parent[x]);
    }
}

void union_find(int x1, int x2)
{
    x1 = get_parent(x1);
    x2 = get_parent(x2);
    if (x1 < x2)
    {
        parent[x2] = x1;
    }
    else
    {
        parent[x1] = x2;
    }
}

ll get_distance(int x1, int y1, int x2, int y2)
{
    return (pow((x2 - x1), 2)) + (pow((y2 - y1), 2));
}

void kruskal()
{
    int cnt = 0;
    ll result = 0;
    for (int i = 1; i < N; i++)
    {
        for (int j = i + 1; j <= N; j++)
        {
            ll distance = get_distance(V[i].first, V[i].second, V[j].first, V[j].second);
            if (distance >= C)
            {
                pq.push({distance, i, j});
            }
        }
    }
    while (!pq.empty())
    {
        ll distance = pq.top().distance;
        int start = pq.top().start;
        int end = pq.top().end;
        pq.pop();
        start = get_parent(start);
        end = get_parent(end);
        if (start != end)
        {
            union_find(start, end);
            result += distance;
            cnt++;
            if (cnt == N - 1)
            {
                break;
            }
        }
    }
    if (cnt != N - 1)
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << result << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> C;
    V.push_back({0, 0});
    for (int i = 1; i <= N; i++)
    {
        int x1, y1;
        cin >> x1 >> y1;
        V.push_back({x1, y1});
        parent[i] = i;
    }
    kruskal();
    return 0;
}
