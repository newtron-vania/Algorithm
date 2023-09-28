#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    stack<int> bag;
    int answer = 0;

    for (int i : moves) {
        i -= 1;
        for (int j = 0; j < board.size(); j++) {
            if (board[j][i] > 0) {
                int value = board[j][i];
                board[j][i] = 0;

                if (bag.size() > 0) {
                    if (bag.top() == value) {
                        answer += 2;
                        bag.pop();
                    }
                    else{
                        bag.push(value);
                    }
                }
                else{
                    bag.push(value);
                }
                break;
            }
        }
    }

    return answer;
}