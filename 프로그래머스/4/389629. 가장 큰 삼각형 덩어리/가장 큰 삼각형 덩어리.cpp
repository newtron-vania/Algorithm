#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1}; // 우 하 좌 상

// [diagonal][position][2 directions]
int dirs[2][2][2] = 
{
    { {2, 3}, {0, 1} }, // / 모양
    { {0, 3}, {1, 2} }  // \ 모양
};

// [a][b] (a: / or \) 모양인 칸에 b 방향으로 진입했을 경우 위(0)인가 아래(1)인가
int positionWhenEntered[2][4] = 
{
    {0, 0, 1, 1}, // \ 모양
    {1, 0, 0, 1}, // / 모양
      
};

int travel(int startX, int startY, int startPosition, vector<vector<int>>& grid, vector<vector<vector<int>>>& been, int groupNum) 
{
    int h = grid.size();
    int w = grid[0].size();
    int ret = 1;
    queue<tuple<int, int, int>> q;

    been[startY][startX][startPosition] = groupNum;
    q.push({startX, startY, startPosition});

    while (!q.empty()) 
    {
        auto [x, y, position] = q.front();
        q.pop();

        int shape = grid[y][x] == 1 ? 0 : 1;
        for(int i = 0; i < 2; i++)
        {
            int dir = dirs[shape][position][i];
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || ny < 0 || nx >= w || ny >= h) continue;

            int nextShape = grid[ny][nx] == 1 ? 0 : 1;
            int nextPosition = positionWhenEntered[nextShape][dir];

            if (been[ny][nx][nextPosition] == groupNum ||
                been[ny][nx][(nextPosition + 1) % 2] == groupNum) 
            {
                continue;
            }

            been[ny][nx][nextPosition] = groupNum;
            q.push({nx, ny, nextPosition});
            ret++;
        }
    }

    return ret;
}

int solution(vector<vector<int>> grid) 
{
    int h = grid.size();
    int w = grid[0].size();
    vector<vector<vector<int>>> been(h, vector<vector<int>>(w, vector<int>(2, 0)));

    int answer = 0;
    int groupNum = 1;

    for (int y = 0; y < h; ++y) 
    {
        for (int x = 0; x < w; ++x) 
        {
            for (int k = 0; k < 2; ++k) 
            {
                if (been[y][x][k] != 0) continue;
                answer = max(answer, travel(x, y, k, grid, been, groupNum++));
            }
        }
    }

    return answer;
}
