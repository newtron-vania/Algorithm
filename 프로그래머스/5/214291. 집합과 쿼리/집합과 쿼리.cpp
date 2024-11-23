#include <bits/stdc++.h>
using namespace std;

int idx, pseudo_par[2020202], real_par[2020202]; 
vector<int> v[2020202];

int pseudo_find(int x) 
{
    while (x != pseudo_par[x]) 
    {
        int next = pseudo_par[x];
        pseudo_par[x] = pseudo_par[next];
        x = next;
    }
    return x;
}

int real_find(int x) 
{
    while (x != real_par[x]) 
    {
        int next = real_par[x];
        real_par[x] = real_par[next];
        x = next;
    }
    return x;
}

void pseudo_merge(int a, int b) 
{
    a = pseudo_find(a);
    b = pseudo_find(b);
    if (a == b) return;

    pseudo_par[b] = idx;
    pseudo_par[idx] = a;

    for (int x : v[b]) 
    {
        real_par[x] = idx;
    }

    v[a].push_back(idx);
    v[b].clear();
    idx++;
}

void real_merge(int a, int b) 
{
    a = real_find(a);
    b = real_find(b);
    if (a == b) return;

    real_par[a] = b;
}

vector<string> solution(int n, vector<vector<int>> queries) 
{
    idx = n;
    vector<string> answer;

    for (int i = 0; i < 2020202; i++) 
    {
        pseudo_par[i] = real_par[i] = i;
        v[i].emplace_back(i);
    }

    for (auto& query : queries) 
    {
        int which = query[0], x = query[1], y = query[2];
        x = real_find(x);
        y = real_find(y);

        if (which == 1) 
        {
            pseudo_merge(x, y);
        } 
        else if (which == 2) 
        {
            int p1 = pseudo_find(x);
            int p2 = pseudo_find(y);
            if (p1 != p2) continue;

            auto& old_set = v[p1];
            auto startIt = find(old_set.begin(), old_set.end(), x);
            auto endIt = find(old_set.begin(), old_set.end(), y);
            if (startIt > endIt) continue;

            for (auto it = startIt; it <= endIt; ++it) 
            {
                pseudo_par[*it] = real_par[*it] = idx;
            }

            old_set.erase(startIt, next(endIt));
            idx++;

            if (pseudo_par[p1] != p1) 
            {
                for (int i : old_set) pseudo_par[i] = idx;

                v[idx].assign(old_set.begin(), old_set.end());
                old_set.clear(); 
                idx++;
            }
        } 
        else 
        {
            x = pseudo_find(x);
            y = pseudo_find(y);
            answer.push_back(x == y ? "Yes" : "No");
        }
    }

    return answer;
}
