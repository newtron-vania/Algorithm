#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

bool Check(int x, int y, vector<string>& board) {
    char c = board[x][y];
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (board[x + i][y + j] != c) {
                return false;
            }
        }
    }
    return true;
}

void SortBoard(vector<string>& board, set<int>& removeXY) {
    for (auto iter = removeXY.begin(); iter != removeXY.end(); iter++) {
        int i = *iter >> 5;
        int j = *iter & 31;
        while(i > 0 && board[i - 1][j] != ' ') {
            board[i][j] = board[i - 1][j];
            board[i - 1][j] = ' ';
            i--;
        }
    }
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;


    set<int> removeXY;
    while (true) {
        removeXY.clear();
        // 2x2 블록을 찾아서 지우기
        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n - 1; j++) {
                if (board[i][j] != ' ' && Check(i, j, board)) {
                    removeXY.insert((i << 5) + j);
                    removeXY.insert((i << 5) + j + 1);
                    removeXY.insert(((i + 1) << 5) + j);
                    removeXY.insert(((i + 1) << 5) + j + 1);
                }
            }
        }
        if (!removeXY.size()) {
            break;
        }
        for (auto iter = removeXY.begin(); iter != removeXY.end(); iter++) {
            board[*iter >> 5][*iter & 31] = ' ';
            answer += 1;
        }

        // 지워진 블록을 빈 공간으로 표시하고, 아래로 떨어뜨리기
        SortBoard(board, removeXY);
    }

    return answer;
}