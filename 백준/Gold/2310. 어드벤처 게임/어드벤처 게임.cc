#include <bits/stdc++.h>
using namespace std;

struct Room
{
    char type;
    int cost;
    vector<int> next;
};

int n;
Room rooms[1001];
int best_money[1001];

bool bfs()
{
    queue<pair<int,int>> q;
    q.push({1, 0});
    memset(best_money, -1, sizeof(best_money));
    best_money[1] = 0;

    while (!q.empty())
    {
        auto [cur, money] = q.front();
        q.pop();

        char t = rooms[cur].type;
        int x = rooms[cur].cost;

        // 방 효과 적용
        if (t == 'L' && money < x) money = x;
        else if (t == 'T')
        {
            if (money < x) continue;
            money -= x;
        }

        if (cur == n) return true;

        for (int nxt : rooms[cur].next)
        {
            if (money > best_money[nxt])
            {
                best_money[nxt] = money;
                q.push({nxt, money});
            }
        }
    }
    return false;
}

int main()
{
    while (true)
    {
        scanf("%d", &n);
        if (n == 0) break;

        for (int i = 1; i <= n; i++)
        {
            char t;
            int c;
            scanf(" %c %d", &t, &c);
            rooms[i].type = t;
            rooms[i].cost = c;
            rooms[i].next.clear();

            while (true)
            {
                int v;
                scanf("%d", &v);
                if (v == 0) break;
                rooms[i].next.push_back(v);
            }
        }

        if (bfs()) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
