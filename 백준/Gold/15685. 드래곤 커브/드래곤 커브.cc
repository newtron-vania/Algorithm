#include <bits/stdc++.h>
using namespace std;

const int MAX = 101;

int n, result;
bool grid[MAX][MAX];

int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};

int end_x, end_y;

vector<int> dragon;

void make_generation(vector<int> &dragon)
{
    int size = dragon.size();

    for (int i = size - 1; i >= 0; i--)
    {
        int dir = (dragon[i] + 1) % 4;
        end_x += dx[dir];
        end_y += dy[dir];
        grid[end_x][end_y] = true;
        dragon.push_back(dir);
    }
}

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int y, x, d, g;
        cin >> y >> x >> d >> g;

        dragon.clear();

        grid[x][y] = true;

        end_x = x + dx[d];
        end_y = y + dy[d];
        grid[end_x][end_y] = true;

        dragon.push_back(d);

        for (int j = 0; j < g; j++)
        {
            make_generation(dragon);
        }
    }

    for (int i = 0; i < MAX - 1; i++)
    {
        for (int j = 0; j < MAX - 1; j++)
        {
            if (grid[i][j] && grid[i][j + 1] && grid[i + 1][j] && grid[i + 1][j + 1])
            {
                result++;
            }
        }
    }

    cout << result << endl;
}
