#include <bits/stdc++.h>

const int MAX_VALUE = 1e6;

using namespace std;

bool visited[MAX_VALUE];
int dimension[11];
int dist[11] = {1, };

int BFS(queue<int> &q, int total, int visited_count)
{
    int day = 0;
    queue<int> cur_q;
    while (!q.empty() && !(visited_count == total))
    {
        day++;
        cur_q = std::move(q);
        while (!cur_q.empty() && !(visited_count == total))
        {
            auto index = cur_q.front();
            cur_q.pop();

            for (int i = 0; i < 22; i++)
            {
                int k = i / 2,
                    sign = 1 - 2 * (i % 2),
                    next_index = index + sign * dist[k],
                    dim_size = dist[k] * dimension[k],
                    lmod = index % dim_size,
                    nmod = next_index % dim_size;

                if (next_index >= 0 && next_index < total && sign * (nmod - lmod) > 0 && !visited[next_index])
                {
                    visited[next_index] = true;
                    visited_count++;
                    q.push(next_index);
                }
            }
        }
    }

    return visited_count == total ? day : -1;
}

int main()
{
    queue<int> q;
    int total = 1;
    for (int i = 0; i < 11; i++)
    {
        scanf("%d", &dimension[i]);
        total *= dimension[i];
    }

    for(int i = 0; i < 11; i++)
    {
        if(i) dist[i] = dimension[i - 1] * dist[i - 1];
    }
    int visited_count = 0;
    for (int i = 0; i < total; i++)
    {
        int v;
        scanf("%d", &v);
        if (v != 0)
        {
            if (v == 1)
            {
                q.push(i);
            }
            visited_count++;
            visited[i] = true;
        }
    }

    cout << BFS(q, total, visited_count) << endl;

    return 0;
}