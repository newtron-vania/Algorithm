#include <bits/stdc++.h>

using namespace std;

int board[10][10];
int paper[6] = {0, 5, 5, 5, 5, 5};
int answer = INT_MAX;

bool canAttach(int x, int y, int size)
{
    if (x + size > 10 || y + size > 10) return false;

    for (int i = x; i < x + size; i++)
    {
        for (int j = y; j < y + size; j++)
        {
            if (board[i][j] == 0) return false;
        }
    }
    return true;
}

void setPaper(int x, int y, int size, int value)
{
    for (int i = x; i < x + size; i++)
    {
        for (int j = y; j < y + size; j++)
        {
            board[i][j] = value;
        }
    }
}

void dfs(int x, int y, int used)
{
    if (x >= 10)
    {
        answer = min(answer, used);
        return;
    }

    if (used >= answer) return;

    if (y >= 10)
    {
        dfs(x + 1, 0, used);
        return;
    }

    if (board[x][y] == 0)
    {
        dfs(x, y + 1, used);
        return;
    }

    for (int size = 5; size >= 1; size--)
    {
        if (paper[size] == 0) continue;
        if (canAttach(x, y, size))
        {
            setPaper(x, y, size, 0);
            paper[size]--;
            dfs(x, y + size, used + 1);
            setPaper(x, y, size, 1);
            paper[size]++;
        }
    }
}

int main()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            scanf("%d", &board[i][j]);
        }
    }

    dfs(0, 0, 0);

    if (answer == INT_MAX)
    {
        printf("-1\n");
    }
    else
    {
        printf("%d\n", answer);
    }

    return 0;
}
