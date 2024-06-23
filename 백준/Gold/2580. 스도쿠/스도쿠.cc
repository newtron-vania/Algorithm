#include <iostream>
#include <vector>
using namespace std;

int board[9][9];
vector<pair<int, int>> emptySpace;
bool over = false;

bool row_arr[9][10] = {false};
bool idx_arr[9][10] = {false};
bool box_arr[9][10] = {false};

void dfs(int cnt) 
{
    if (over) 
        return;
    if (cnt >= emptySpace.size()) 
    {
        for (int i = 0; i < 9; i++) 
        {
            for (int j = 0; j < 9; j++) 
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        over = true;
        return;
    }

    int y = emptySpace[cnt].first;
    int x = emptySpace[cnt].second;

    for (int i = 1; i < 10; i++) 
    {
        if (!row_arr[y][i] && !idx_arr[x][i] && !box_arr[y / 3 * 3 + x / 3][i]) 
        {
            row_arr[y][i] = idx_arr[x][i] = box_arr[y / 3 * 3 + x / 3][i] = true;
            board[y][x] = i;
            dfs(cnt + 1);
            row_arr[y][i] = idx_arr[x][i] = box_arr[y / 3 * 3 + x / 3][i] = false;
            board[y][x] = 0;
        }
    }
}

int main() 
{
    for (int i = 0; i < 9; i++) 
    {
        for (int j = 0; j < 9; j++) 
        {
            cin >> board[i][j];
            if (board[i][j] == 0)
                emptySpace.push_back(make_pair(i, j));
            else 
            {
                row_arr[i][board[i][j]] = true;
                idx_arr[j][board[i][j]] = true;
                box_arr[i / 3 * 3 + j / 3][board[i][j]] = true;
            }
        }
    }
    dfs(0);
    return 0;
}
