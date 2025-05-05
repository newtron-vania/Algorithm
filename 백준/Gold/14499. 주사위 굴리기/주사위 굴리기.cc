#include <bits/stdc++.h>
using namespace std;

int n, m, x, y, k;
int orders[1000];
int board[20][20];  // 이름 충돌 해결
int a[4] = {0, 0, 0, 0};
int b[4] = {0, 0, 0, 0};

int main()
{
    cin >> n >> m >> x >> y >> k;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < k; ++i)
    {
        cin >> orders[i];
    }

    for (int i = 0; i < k; ++i)
    {
        if (orders[i] == 1 && y + 1 >= m)
        {
            continue;
        }
        else if (orders[i] == 1)
        {
            int temp = a[0];
            a[0] = a[1];
            a[1] = a[2];
            a[2] = a[3];
            a[3] = temp;
            b[1] = a[1];
            b[3] = a[3];
            y = y + 1;
            if (board[x][y] == 0)
            {
                board[x][y] = a[1];
            }
            else
            {
                a[1] = board[x][y];
                b[1] = board[x][y];
                board[x][y] = 0;
            }
        }

        if (orders[i] == 2 && y - 1 < 0)
        {
            continue;
        }
        else if (orders[i] == 2)
        {
            int temp = a[3];
            a[3] = a[2];
            a[2] = a[1];
            a[1] = a[0];
            a[0] = temp;
            b[1] = a[1];
            b[3] = a[3];
            y = y - 1;
            if (board[x][y] == 0)
            {
                board[x][y] = a[1];
            }
            else
            {
                a[1] = board[x][y];
                b[1] = board[x][y];
                board[x][y] = 0;
            }
        }

        if (orders[i] == 3 && x - 1 < 0)
        {
            continue;
        }
        else if (orders[i] == 3)
        {
            int temp = b[3];
            b[3] = b[2];
            b[2] = b[1];
            b[1] = b[0];
            b[0] = temp;
            a[1] = b[1];
            a[3] = b[3];
            x = x - 1;
            if (board[x][y] == 0)
            {
                board[x][y] = a[1];
            }
            else
            {
                a[1] = board[x][y];
                b[1] = board[x][y];
                board[x][y] = 0;
            }
        }

        if (orders[i] == 4 && x + 1 >= n)
        {
            continue;
        }
        else if (orders[i] == 4)
        {
            int temp = b[0];
            b[0] = b[1];
            b[1] = b[2];
            b[2] = b[3];
            b[3] = temp;
            a[1] = b[1];
            a[3] = b[3];
            x = x + 1;
            if (board[x][y] == 0)
            {
                board[x][y] = a[1];
            }
            else
            {
                a[1] = board[x][y];
                b[1] = board[x][y];
                board[x][y] = 0;
            }
        }

        cout << a[3] << endl;
    }
}
