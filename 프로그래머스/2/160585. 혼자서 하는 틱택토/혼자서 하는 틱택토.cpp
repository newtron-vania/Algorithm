#include <string>
#include <vector>
#include <iostream>

using namespace std;

pair<int, int> CountCheck(vector<string>& board)
{
    int count_O = 0;
    int count_X = 0;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(board[i][j] == 'O')
            {
                count_O++;
            }
            if(board[i][j] == 'X')
            {
                count_X++;
            }
        }
    }
    return make_pair(count_O, count_X);
}

int WinCheck(vector<string>& board, char type)
{
    int win_count = 0;
    int count_right = 0;
    int count_left = 0;
    for(int i = 0 ; i < 3; i++)
    {
        if(board[i][0] == type && board[i][1] == type && board[i][2] == type)
        {
            win_count++;
        }
        if(board[0][i] == type && board[1][i] == type && board[2][i] == type)
        {
            win_count++;
        }
        if(board[i][i] == type)
        {
            count_right++;
        }
        if(board[i][2-i] == type)
        {
            count_left++;
        }
    }
    if(count_right == 3)
    {
        win_count++;
    }
    if(count_left == 3)
    {
        win_count++;
    }
    return win_count;
}


int solution(vector<string> board) {
    int answer = 1;
    auto counts = CountCheck(board);
    int count_O = counts.first;
    int count_X = counts.second;
    
    int win_O_count = WinCheck(board, 'O');
    int win_X_count = WinCheck(board, 'X');
    
    if((count_O < count_X || count_O - count_X > 1) ||  (win_O_count > 0 && count_O <= count_X) || (win_X_count > 0 && count_O > count_X) )
    {
        answer = 0;
    }
    
    return answer;
}