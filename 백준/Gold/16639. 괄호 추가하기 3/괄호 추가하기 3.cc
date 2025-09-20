#include <bits/stdc++.h>
using namespace std;

int max_val[101][101];
int min_val[101][101];
char s[101];

int cal(int a, int b, char op)
{
    if (op == '+') return a + b;
    else if (op == '-') return a - b;
    else return a * b;
}

int main()
{
    int n;
    scanf("%d", &n);
    scanf("%s", s);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            max_val[i][j] = INT_MIN;
            min_val[i][j] = INT_MAX;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (isdigit(s[i]))
        {
            max_val[i][i] = min_val[i][i] = s[i] - '0';
        }
    }

    for (int j = 2; j < n; j += 2)
    {
        for (int i = 0; i + j < n; i += 2)
        {
            for (int k = 2; k <= j; k += 2)
            {
                int tmp[4];
                tmp[0] = cal(min_val[i][i + k - 2], min_val[i + k][i + j], s[i + k - 1]);
                tmp[1] = cal(min_val[i][i + k - 2], max_val[i + k][i + j], s[i + k - 1]);
                tmp[2] = cal(max_val[i][i + k - 2], min_val[i + k][i + j], s[i + k - 1]);
                tmp[3] = cal(max_val[i][i + k - 2], max_val[i + k][i + j], s[i + k - 1]);

                sort(tmp, tmp + 4);

                min_val[i][i + j] = min(min_val[i][i + j], tmp[0]);
                max_val[i][i + j] = max(max_val[i][i + j], tmp[3]);
            }
        }
    }

    printf("%d\n", max_val[0][n - 1]);

    return 0;
}
