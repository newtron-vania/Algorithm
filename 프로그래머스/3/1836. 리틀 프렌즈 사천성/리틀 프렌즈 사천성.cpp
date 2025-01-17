#include <bits/stdc++.h>

using namespace std;

char gameBoard[110][110];
int numRows, numCols;

int directionX[4] = {-1, 1, 0, 0};
int directionY[4] = {0, 0, -1, 1};

bool isValidPosition(int x, int y) 
{
    return (0 <= x && x < numRows && 0 <= y && y < numCols);
}

bool canMatchTiles(int startX, int startY) 
{
    char targetChar = gameBoard[startX][startY];
    
    for (int dir = 0; dir < 4; dir++) 
    {
        int currentX = startX + directionX[dir];
        int currentY = startY + directionY[dir];

        while (isValidPosition(currentX, currentY) && 
               (gameBoard[currentX][currentY] == '.' || gameBoard[currentX][currentY] == targetChar)) 
        {
            if (gameBoard[currentX][currentY] == targetChar) 
            {
                gameBoard[startX][startY] = '.';
                gameBoard[currentX][currentY] = '.';
                return true;
            }

            for (int nextDir = 0; nextDir < 4; nextDir++) 
            {
                if (dir == nextDir || 
                    (dir == 0 && nextDir == 1) || (dir == 1 && nextDir == 0) || 
                    (dir == 2 && nextDir == 3) || (dir == 3 && nextDir == 2)) 
                {
                    continue;
                }

                int nextX = currentX + directionX[nextDir];
                int nextY = currentY + directionY[nextDir];

                while (isValidPosition(nextX, nextY) && 
                       (gameBoard[nextX][nextY] == '.' || gameBoard[nextX][nextY] == targetChar)) 
                {
                    if (gameBoard[nextX][nextY] == targetChar) 
                    {
                        gameBoard[startX][startY] = '.';
                        gameBoard[nextX][nextY] = '.';
                        return true;
                    }

                    nextX += directionX[nextDir];
                    nextY += directionY[nextDir];
                }
            }

            currentX += directionX[dir];
            currentY += directionY[dir];
        }
    }

    return false;
}

string solution(int m, int n, vector<string> board) 
{
    string result = "";
    numRows = m;
    numCols = n;

    vector<pair<char, pair<int, int>>> tilePositions;
    map<char, int> visitedTiles;

    for (int i = 0; i < m; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            gameBoard[i][j] = board[i][j];

            if ('A' <= gameBoard[i][j] && gameBoard[i][j] <= 'Z' && visitedTiles[gameBoard[i][j]] == 0) 
            {
                visitedTiles[gameBoard[i][j]] = 1;
                tilePositions.push_back({gameBoard[i][j], {i, j}});
            }
        }
    }
    sort(tilePositions.begin(), tilePositions.end());

    bool hasMatched = true;
    while (hasMatched) 
    {
        hasMatched = false;

        for (int i = 0; i < tilePositions.size(); i++) 
        {
            hasMatched = canMatchTiles(tilePositions[i].second.first, tilePositions[i].second.second);

            if (hasMatched) 
            {
                result += tilePositions[i].first;
                tilePositions.erase(tilePositions.begin() + i);
                break;
            }
        }
    }

    if (!tilePositions.empty()) 
    {
        result = "IMPOSSIBLE";
    }

    return result;
}
