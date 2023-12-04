#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;
typedef pair<int, int> pos;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int BFS(int x, int y, vector<string> maps, vector<vector<bool>>& visited)
{
    if(visited[x][y])
        return 0;
    int result = 0;
    
    queue<pos> q;
    q.push(pair(x, y));
    visited[x][y] = true;
    while(!q.empty())
    {
        auto node = q.front();
        q.pop();
        result += maps[node.first][node.second] - '0';
        for(int i = 0; i < 4; i++)
        {
            int mx = node.first + dx[i], my = node.second + dy[i];
            if(mx < 0 || my < 0 || mx >= maps.size() || my >= maps[0].length())
                continue;
            if(maps[mx][my] == 'X' || visited[mx][my])
                continue;
            visited[mx][my] = true;    
            q.push(pair(mx,my));
        }
    }
    return result;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    vector<vector<bool>> visited(maps.size(), vector<bool>(maps[0].length(), false));
    
    for(int col = 0; col < maps.size(); col++)
    {
        for(int row = 0; row < maps[0].length(); row++)
        {
            if(maps[col][row] != 'X' && !visited[col][row])
            {
                answer.push_back(BFS(col, row, maps, visited));
            }
        }
    }
    if(answer.size() > 0)
    {
        sort(answer.begin(), answer.end());
        return answer;
    }
    else
    {
        return {-1};
    }
}