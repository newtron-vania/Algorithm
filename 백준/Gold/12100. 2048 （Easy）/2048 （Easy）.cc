#include <bits/stdc++.h>

using namespace std;

int N, res = 0;
int A[20][20];

void up(int a[][20])
{
    bool check[20][20];

    memset(check, false, sizeof(check));

    for (int j = 0; j < N; j++) 
    {
        while(true)
        {
            bool tf = false;

            for (int i = 1; i < N; i++) 
            {
                if (a[i][j] == 0) continue;

                if (a[i - 1][j] == 0)
                {
                    a[i - 1][j] = a[i][j];
                    a[i][j] = 0;
                    tf = true;

                    if (check[i][j]) {
                        check[i - 1][j] = true;
                        check[i][j] = false;
                    }
                }
                else if (a[i - 1][j] == a[i][j] && !check[i - 1][j] && !check[i][j]) 
                {
                    a[i - 1][j] += a[i][j];
                    a[i][j] = 0;
                    tf = true;
                    check[i - 1][j] = true;
                }
            }

            if (!tf) break;
        }
    }
}

void down(int a[][20]) 
{
    bool check[20][20];

    memset(check, false, sizeof(check));

    for (int j = 0; j < N; j++) 
    {
        while (1) 
        {
            bool tf = false;

            for (int i = N-2; i >= 0; i--) 
            {
                if (a[i][j] == 0) continue;

                if (a[i + 1][j] == 0) 
                {
                    a[i + 1][j] = a[i][j];
                    a[i][j] = 0;
                    tf = true;

                    if (check[i][j]) 
                    {
                        check[i + 1][j] = true;
                        check[i][j] = false;
                    }
                }
                else if (a[i + 1][j] == a[i][j] && !check[i+1][j] && !check[i][j]) 
                {
                    a[i + 1][j] += a[i][j];
                    a[i][j] = 0;
                    tf = true;
                    check[i + 1][j] = true;
                }
            }

            if (!tf) break;
        }
    }
}

void left(int a[][20])
{
    bool check[20][20];

    memset(check, false, sizeof(check));

    for (int i = 0; i < N; i++) 
    {
        while (1) {
            bool tf = false;

            for (int j = 1; j < N; j++) 
            {
                if (a[i][j] == 0) continue;

                if (a[i][j - 1] == 0) 
                {
                    a[i][j - 1] = a[i][j];
                    a[i][j] = 0;
                    tf = true;

                    if (check[i][j]) 
                    {
                        check[i][j - 1] = true;
                        check[i][j] = false;
                    }
                }
                else if (a[i][j - 1] == a[i][j] && !check[i][j-1] && !check[i][j])
                {
                    a[i][j - 1] += a[i][j];
                    a[i][j] = 0;
                    tf = true;
                    check[i][j - 1] = true;
                }
            }

            if (!tf) break;
        }
    }
}

void right(int a[][20]) 
{
    bool check[20][20];

    memset(check, false, sizeof(check));

    for (int i = 0; i < N; i++)
    {
        while (1) {
            bool tf = false;

            for (int j = N-2; j >= 0; j--) 
            {
                if (a[i][j] == 0) continue;

                if (a[i][j + 1] == 0) 
                {
                    a[i][j + 1] = a[i][j];
                    a[i][j] = 0;
                    tf = true;

                    if (check[i][j]) 
                    {
                        check[i][j + 1] = true;
                        check[i][j] = false;
                    }
                }
                else if (a[i][j + 1] == a[i][j] && !check[i][j+1] && !check[i][j]) 
                {
                    a[i][j + 1] += a[i][j];
                    a[i][j] = 0;
                    tf = true;
                    check[i][j + 1] = true;
                }
            }

            if (!tf) break;
        }
    }
}

void dfs(int depth, int a[][20]) 
{
    if (depth == 5) 
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++) 
            {
                res = max(res, a[i][j]);
            }
        }

        return;
    }
    int tmp[20][20];

    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++)
        {
            tmp[i][j] = a[i][j];
        }
    }

    for (int i = 0; i < 4; i++)
    {
        switch (i)
        {
        case 0:
            up(a);
            break;
        case 1:
            down(a);
            break;
        case 2:
            left(a);
            break;
        case 3:
            right(a);
            break;
        }

        dfs(depth + 1, a);

        for (int i = 0; i < N; i++) 
        {
            for (int j = 0; j < N; j++) 
            {
                a[i][j] = tmp[i][j];
            }
        }
    }
}

void solution() {
    dfs(0, A);

    cout << res;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++) 
        {
            cin >> A[i][j];
        }
    }

    solution();

    return 0;
}