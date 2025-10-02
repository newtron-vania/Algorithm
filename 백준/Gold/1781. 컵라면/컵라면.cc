#include <bits/stdc++.h>
using namespace std;

const int MAX = 200001;

int N;
vector<int> problems[MAX];

int optimize()
{
    int ret = 0;
    priority_queue<int, vector<int>, less<int>> pq;
    
    for (int day = N; day >= 1; day--)
    {
        for (auto p : problems[day])
        {
            pq.push(p);
        }
        if (!pq.empty())
        {
            ret += pq.top();
            pq.pop();
        }
    }
    
    return ret;
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        int deadLine, ramen;
        scanf("%d %d", &deadLine, &ramen);
        problems[deadLine].push_back(ramen);
    }
    
    printf("%d\n", optimize());
    return 0;
}
