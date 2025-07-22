#include <bits/stdc++.h>

const int MAX_VALUE = 1e6;

using namespace std;

bool visited[MAX_VALUE];
int dimension[11];

int BFS(queue<int> &q, int size, int visited_count)
{
    int day = 0;
    queue<int> cur_q;
    while (!q.empty() && !(visited_count == size))
    {
        day++;
        cur_q = std::move(q);
        while (!cur_q.empty() && !(visited_count == size))
        {
            auto cp = cur_q.front();
            cur_q.pop();

            int dimension_value = 1;
            for (int i = 0; i < 11; i++)
            {
                if (i != 0)
                    dimension_value *= dimension[i - 1];

                int dimension_check_value = dimension_value * dimension[i];
                for (int v : {cp + dimension_value, cp - dimension_value})
                {
                    if (v < 0 || v >= size)
                        continue;
                    if (visited[v])
                        continue;
                    if ((v / dimension_check_value) != (cp / dimension_check_value))
                        continue;

                    visited[v] = true;
                    visited_count++;

                    q.push(v);
                }
            }
        }
    }

    return visited_count == size ? day : -1;
}

int main()
{
    queue<int> q;
    int size = 1;
    for (int i = 0; i < 11; i++)
    {
        scanf("%d", &dimension[i]);
        size *= dimension[i];
    }
    int visited_count = 0;
    for (int i = 0; i < size; i++)
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

    cout << BFS(q, size, visited_count) << endl;

    return 0;
}