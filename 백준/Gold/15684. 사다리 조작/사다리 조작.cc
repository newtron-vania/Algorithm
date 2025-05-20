#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 10;
const int MAX_H = 30;

int n, m, h;
int graph[MAX_H][MAX_N];
int ans = 4;

bool Check()
{
    for (int i = 0; i < n; i++)
    {
        int temp = i;
        for (int j = 0; j < h; j++)
        {
            if (graph[j][temp])
            {
                temp++;
            }
            else if (temp > 0 && graph[j][temp - 1])
            {
                temp--;
            }
        }
        if (temp != i)
        {
            return false;
        }
    }
    return true;
}

void DFS(int cnt, int x, int y)
{
    if (ans <= cnt)
    {
        return;
    }
    if (Check())
    {
        ans = min(ans, cnt);
        return;
    }
    if (cnt == 3)
    {
        return;
    }
    for (int i = x; i < h; i++)
    {
        int k = (i == x) ? y : 0;
        for (int j = k; j < n - 1; j++)
        {
            if (graph[i][j] == 0 && graph[i][j + 1] == 0)
            {
                graph[i][j] = 1;
                DFS(cnt + 1, i, j + 2);
                graph[i][j] = 0;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> h;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a - 1][b - 1] = 1;
    }

    DFS(0, 0, 0);
    cout << (ans <= 3 ? ans : -1) << endl;

    return 0;
}