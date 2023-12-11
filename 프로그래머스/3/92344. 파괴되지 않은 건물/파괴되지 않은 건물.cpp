#include <string>
#include <vector>
 
using namespace std;
 
int accSum[1010][1010];
 
void calculateAccSum(vector<vector<int>> board, vector<vector<int>> skills) {
    for (auto skill : skills) {
        int type = skill[0];
        int x = skill[1];
        int y = skill[2];
        int xx = skill[3];
        int yy = skill[4];
        int degree = skill[5];
        degree = type == 1 ? degree * -1 : degree;
        
        accSum[x][y] += degree;
        accSum[xx + 1][yy + 1] += degree;
        accSum[x][yy + 1] -= degree;
        accSum[xx + 1][y] -= degree;
    }
 
    for (int i = 0; i <= board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            accSum[i][j + 1] += accSum[i][j];
        }
    }
 
    for (int j = 0; j <= board[0].size(); j++) {
        for (int i = 0; i < board.size(); i++) {
            accSum[i + 1][j] += accSum[i][j];
        }
    }
}
 
int findAnswer(vector<vector<int>> board) {
    int answer = 0;
    for (int i = 0; i <board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (board[i][j] + accSum[i][j] > 0) {
                answer++;
            }
        }
    }
    return answer;
}
 
int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    calculateAccSum(board, skill);
    answer = findAnswer(board);
    return answer;
}