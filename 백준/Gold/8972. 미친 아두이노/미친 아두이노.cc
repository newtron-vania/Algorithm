#include <bits/stdc++.h>

using namespace std;

char mpa[101][101];
char tmp_mpa[101][101];
int check[101][101];

int dx[10] = {0, 1, 1, 1, 0, 0, 0, -1, -1, -1};
int dy[10] = {0, -1, 0, 1, -1, 0, 1, -1, 0, 1};

int main()
{
    int R, C;
    scanf("%d %d", &R, &C);

    int Ix = 0, Iy = 0;
    bool gameover = false;
    int X = 0;

    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            scanf(" %c", &mpa[i][j]);
            if (mpa[i][j] == 'I')
            {
                Ix = i;
                Iy = j;
            }
        }
    }

    char S[10001];
    scanf("%s", S);

    for (int k = 0; S[k]; k++)
    {
        memset(check, 0, sizeof(check));
        for (int i = 1; i <= R; i++)
        {
            for (int j = 1; j <= C; j++)
            {
                tmp_mpa[i][j] = '.';
            }
        }

        Ix += dx[S[k] - '0'];
        Iy += dy[S[k] - '0'];
        X++;

        if (mpa[Ix][Iy] == 'R')
        {
            printf("kraj %d\n", X);
            gameover = true;
            break;
        }

        tmp_mpa[Ix][Iy] = 'I';

        for (int i = 1; i <= R; i++)
        {
            for (int j = 1; j <= C; j++)
            {
                if (mpa[i][j] == 'R')
                {
                    int minDist = 1e9;
                    int bestDir = 0;

                    for (int d = 1; d <= 9; d++)
                    {
                        if (d == 5) continue;
                        int nx = i + dx[d];
                        int ny = j + dy[d];
                        int dist = abs(Ix - nx) + abs(Iy - ny);
                        if (dist < minDist)
                        {
                            minDist = dist;
                            bestDir = d;
                        }
                    }

                    int nx = i + dx[bestDir];
                    int ny = j + dy[bestDir];

                    check[nx][ny]++;
                }
            }
        }

        if (check[Ix][Iy] > 0)
        {
            printf("kraj %d\n", X);
            gameover = true;
            break;
        }

        for (int i = 1; i <= R; i++)
        {
            for (int j = 1; j <= C; j++)
            {
                if (check[i][j] == 1)
                {
                    tmp_mpa[i][j] = 'R';
                }
            }
        }

        for (int i = 1; i <= R; i++)
        {
            for (int j = 1; j <= C; j++)
            {
                mpa[i][j] = tmp_mpa[i][j];
            }
        }
    }

    if (!gameover)
    {
        for (int i = 1; i <= R; i++)
        {
            for (int j = 1; j <= C; j++)
            {
                printf("%c", mpa[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}
