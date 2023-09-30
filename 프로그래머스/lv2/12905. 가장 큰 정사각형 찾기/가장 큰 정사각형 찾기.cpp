#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 0;
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (!board[i][j])
                continue;
            int width = j - 1 >= 0 ? board[i][j - 1] : 0;
            int height = i - 1 >= 0 ? board[i - 1][j] : 0;
            int length = min(width, height);
            board[i][j] = board[i - length][j - length] > 0 ?
                length + 1 : length;


            answer = max(answer, board[i][j]* board[i][j]);
        }
    }

    return answer;
}