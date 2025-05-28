#include <bits/stdc++.h>
using namespace std;

vector<int> tree_map[11][11];
int a[11][11] = { 0 };
int ground[11][11] = { 0 };
int n, m, k;
vector<tuple<int, int, int>> dead;

int dx[8] = { -1,-1,-1,0,0,1,1,1 };
int dy[8] = { -1,0,1,-1,1,-1,0,1 };

void input()
{
    cin >> n >> m >> k;
    for (int r = 1; r <= n; r++)
    {
        for (int c = 1; c <= n; c++)
        {
            ground[r][c] = 5;
        }
    }
    for (int r = 1; r <= n; r++)
    {
        for (int c = 1; c <= n; c++)
        {
            cin >> a[r][c];
        }
    }
    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        tree_map[x][y].push_back(z);
    }
}

void spring()
{
    for (int r = 1; r <= n; r++)
    {
        for (int c = 1; c <= n; c++)
        {
            sort(tree_map[r][c].begin(), tree_map[r][c].end());
        }
    }

    for (int r = 1; r <= n; r++)
    {
        for (int c = 1; c <= n; c++)
        {
            for (int i = 0; i < tree_map[r][c].size(); i++)
            {
                if (ground[r][c] >= tree_map[r][c][i])
                {
                    ground[r][c] -= tree_map[r][c][i];
                    tree_map[r][c][i]++;
                }
                else
                {
                    dead.push_back({ r, c, tree_map[r][c][i] });
                    tree_map[r][c].erase(tree_map[r][c].begin() + i);
                    i--;
                }
            }
        }
    }
}

void summer()
{
    for (int i = dead.size() - 1; i >= 0; i--)
    {
        int r, c, age;
        tie(r, c, age) = dead[i];
        ground[r][c] += age / 2;
    }
    dead.clear();
}

void fall()
{
    for (int r = 1; r <= n; r++)
    {
        for (int c = 1; c <= n; c++)
        {
            for (int i = 0; i < tree_map[r][c].size(); i++)
            {
                if (tree_map[r][c][i] % 5 == 0 && tree_map[r][c][i] >= 5)
                {
                    for (int j = 0; j < 8; j++)
                    {
                        int nx = r + dx[j];
                        int ny = c + dy[j];
                        if (1 <= nx && nx <= n && 1 <= ny && ny <= n)
                        {
                            tree_map[nx][ny].push_back(1);
                        }
                    }
                }
            }
        }
    }
}

void winter()
{
    for (int r = 1; r <= n; r++)
    {
        for (int c = 1; c <= n; c++)
        {
            ground[r][c] += a[r][c];
        }
    }
}

int main()
{
    input();
    while (k--)
    {
        spring();
        summer();
        fall();
        winter();
    }
    int answer = 0;
    for (int r = 1; r <= n; r++)
    {
        for (int c = 1; c <= n; c++)
        {
            answer += tree_map[r][c].size();
        }
    }
    cout << answer;
    return 0;
}
