#include <string>
#include <vector>
#include <iostream>
using namespace std;
 
int row, col;
int blockCnt;
int black = -1;
int boomCnt;
vector<vector<int>> copy_board(55, vector<int>(55));
 
void copy(vector<vector<int>> &to, vector<vector<int>> &from)
{
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            to[i][j] = from[i][j];
        }
    }
}
 
int isSquare(int x, int y, int shape, int color, vector<vector<int>> &board) // shape(0): 2*3 , shape(1): 3*2
{
    int colorCnt = 0;
    int blackCnt = 0;
    
    if(shape == 0)
    {
        for(int i = x; i <= x+1; i++)
        {
            for(int j = y; j <= y+2; j++)
            {
                if(board[i][j] == color)
                {
                    colorCnt++;
                }
                else if(board[i][j] == black)
                {
                    blackCnt++;
                }
            }
        }
    }
    else
    {
        for(int i = x; i <= x+2; i++)
        {
            for(int j = y; j <= y+1; j++)
            {
                if(board[i][j] == color)
                {
                    colorCnt++;
                }
                else if(board[i][j] == black)
                {
                    blackCnt++;
                }
            }
        }
    }
    
    if(colorCnt == 4 && blackCnt == 2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
 
void print(vector<vector<int>> &board)
{
    for(int i = 0; i < col; i++)
    {
        for(int j = 0; j < row; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
 
void bomb(int x, int y, int shape, vector<vector<int>> &board)
{
    if(shape == 0)
    {
        for(int i = x; i <= x+1; i++)
        {
            for(int j = y; j <= y+2; j++)
            {
                board[i][j] = 0;
                copy_board[i][j] = 0;
            }
        }
    }
    else
    {
        for(int i = x; i <= x+2; i++)
        {
            for(int j = y; j <= y+1; j++)
            {
                board[i][j] = 0;
                copy_board[i][j] = 0;
            }
        }
    }   
}
 
bool fall(vector<vector<int>> &board)
{
    bool boomCheck = false;
    copy(copy_board, board);
    
    // 검은 블록 떨어뜨리기
    for(int i = 0; i < col; i++)
    {    
        for(int j = 0; j < row; j++)
        {   
            if(board[j][i] != 0)
            {
                break;
            }
            
            board[j][i] = black;
         }
    }
    
    // print(board);
    
    for(int i = 1; i <= blockCnt; i++)
    {
        // 2*3 모양
        for(int j = 0; j <= row-2; j++)
        {
            for(int k = 0; k <= col-3; k++)
            {
                if(isSquare(j, k, 0, i, board))
                {
                    boomCheck = true;
                    bomb(j, k, 0, board);
                    boomCnt++;
                }
            }
        }
        
        // 3*2 모양
        for(int j = 0; j <= row-3; j++)
        {
            for(int k = 0; k <= col-2; k++)
            {
                if(isSquare(j, k, 1, i, board))
                {
                    boomCheck = true;
                    bomb(j, k, 1, board);
                    boomCnt++;
                }
            }
        }
    }
    
    copy(board, copy_board);
    
    // print(board);
    
    return boomCheck;
}
 
int solution(vector<vector<int>> board) 
{
    row = board.size();
    col = row;
      
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if(board[i][j] > blockCnt)
            {
                blockCnt = board[i][j];
            }
        }
    }
    
    while(1)
    {
        bool check = fall(board);
        
        if(check == false)
        {
            break;
        }
    }       
    
    return boomCnt;
}
