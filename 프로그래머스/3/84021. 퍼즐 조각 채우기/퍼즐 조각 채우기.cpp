#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

int visited[51][51];
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

vector<vector<pair<int,int>>> allPairs;

void dfs(int y, int x, int n, vector<pair<int,int>> &block, vector<vector<int>> &table)
{
    if(visited[y][x])
		return;
    if(table[y][x] == 0)
		return;
    visited[y][x] = 1;
    block.push_back({ y, x });

    for(int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
		int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
        dfs(ny, nx, n, block, table);
    }
}

bool solve(vector<vector<int>> &board, vector<pair<int,int>> block) 
{
    int n = board.size();

    for(int r = -n + 1; r < n; r++) 
    {
        for(int c = -n + 1; c < n; c++) 
        {
            vector<pair<int,int>> fitblock;
            for(auto b : block)
            {
                fitblock.push_back({b.first + r, b.second + c});
            }
				
            int cnt = 0;
            for(int i = 0; i < fitblock.size(); i++) 
            {
                pair<int,int> cur = fitblock[i];
                if(cur.first < 0 || cur.second < 0 || cur.first >= n || cur.second >= n) break;
                if(board[cur.first][cur.second] == 1) break;
                cnt++;
            }
            if(cnt == fitblock.size()) 
            {
                bool fit = true;
                for(auto a : fitblock)
                {
                    board[a.first][a.second] = 1;
                }
					
                for(int i = 0; i < fitblock.size(); i++)
                {
                    pair<int,int> cur = fitblock[i];
                    
                    for(int d = 0; d < 4; d++)
                    {
                        int ny = cur.first + dy[d];
						int nx = cur.second + dx[d];
                        
                        if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
                        
                        if(board[ny][nx] == 0) 
                        {
                            fit = false;
							break;
                        }
                    }
                    if(fit == false) break;
                }
                if(fit == false) 
                {
                    for(auto a : fitblock)
                    {
                        board[a.first][a.second] = 0;
                    }
                } else 
                {
					return true;
				}
            }
        }
    }
    return false;
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table)
{
    int answer = 0;
    int n = table.size();

    for(int i = 0; i < table.size(); i++)
    {
        for(int j = 0; j < table[0].size(); j++) 
        {
            if(table[i][j] == 1)
            {
                vector<pair<int,int>> block;
                dfs(i, j, table.size(), block, table);
                if(block.size()) allPairs.push_back(block);
            }
        }
    }

    vector<vector<int>> rotateBoard(n, vector<int>(n,0));
    vector<bool> pairsVis(allPairs.size(), false);
    for(int rot = 0; rot < 4; rot++)
    {
        for(int r = 0; r < n; r++) 
        {
            for(int c = 0; c < n; c++) 
            {
                rotateBoard[r][c] = game_board[c][n-r-1];
            }
        }

        for(int i = 0; i < allPairs.size(); i++) 
        {
            if(pairsVis[i] == 0 && solve(rotateBoard, allPairs[i])) 
            {
                answer += allPairs[i].size();
                pairsVis[i] = 1;
            }
        }

        for(int r = 0; r < n; r++) 
        {
            for(int c = 0; c < n; c++) 
            {
                game_board[r][c] = rotateBoard[r][c];
            }
        }
    }

    return answer;
}