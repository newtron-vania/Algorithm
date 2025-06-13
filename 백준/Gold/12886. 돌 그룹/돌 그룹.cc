#include <bits/stdc++.h>

using namespace std;

bool visited[1501][1501];
int abc[3];
int total;

void input()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 3; ++i)
    {
        cin >> abc[i];
    }

    total = abc[0] + abc[1] + abc[2];
}

bool dfs(int a, int b)
{
    int c = total - a - b;
    int stones[3] = { a, b, c };
    sort(stones, stones + 3);
    a = stones[0];
    b = stones[1];
    c = stones[2];

    if (a == b && b == c)
    {
        return true;
    }

    if (visited[a][b])
    {
        return false;
    }

    visited[a][b] = true;

    // 가능한 두 그룹 쌍들
    int pairs[3][2] = { {a, b}, {a, c}, {b, c} };

    for (int i = 0; i < 3; ++i)
    {
        int x = pairs[i][0];
        int y = pairs[i][1];

        if (x == y) continue;

        int nx = x + x;
        int ny = y - x;

        if (nx > total || ny > total || ny < 0) continue;

        int na = nx;
        int nb = ny;
        int nc = total - na - nb;

        if (dfs(na, nb))
        {
            return true;
        }
    }

    return false;
}

int main()
{
    input();
    
    cout << dfs(abc[0], abc[1]);

    return 0;
}
