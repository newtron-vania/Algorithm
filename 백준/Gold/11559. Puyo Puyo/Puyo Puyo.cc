#include <bits/stdc++.h>

using namespace std;

char MAP[12][6];
bool Visit[12][6];

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int Temp_Cnt = 0;
vector<pair<int,int>> Boom_Tmp, Boom_Vec;


void DFS(int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= 12 || ny >= 6) continue;
        if (MAP[nx][ny] == '.') continue;
        if (Visit[nx][ny]) continue;
        if (MAP[x][y] != MAP[nx][ny]) continue;

        Temp_Cnt++;
        Visit[nx][ny] = true;
        Boom_Tmp.push_back({nx, ny});
        DFS(nx, ny);
    }
}

int main()
{
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            scanf(" %c", &MAP[i][j]);
        }
    }
    
    int Answer = 0;

    while (true)
    {
        bool Flag = false;
        memset(Visit, false, sizeof(Visit));
        Boom_Vec.clear();

        for (int i = 0; i < 12; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                if (MAP[i][j] != '.' && !Visit[i][j])
                {
                    Temp_Cnt = 1;
                    Boom_Tmp.push_back({i, j});
                    Visit[i][j] = true;

                    DFS(i, j);

                    if (Temp_Cnt >= 4)
                    {
                        Flag = true;
                        for (int k = 0; k < (int)Boom_Tmp.size(); k++)
                        {
                            Boom_Vec.push_back(Boom_Tmp[k]);
                        }
                    }
                    Boom_Tmp.clear();
                }
            }
        }

        for (int i = 0; i < (int)Boom_Vec.size(); i++)
        {
            int x = Boom_Vec[i].first;
            int y = Boom_Vec[i].second;
            MAP[x][y] = '.';
        }

        for (int i = 10; i >= 0; i--)
        {
            for (int j = 0; j < 6; j++)
            {
                if (MAP[i][j] == '.') continue;

                int h = i;
                while (h < 11 && MAP[h + 1][j] == '.')
                {
                    MAP[h + 1][j] = MAP[h][j];
                    MAP[h][j] = '.';
                    h++;
                }
            }
        }

        if (Flag) Answer++;
        else break;
    }

    printf("%d\n", Answer);
}
