#include <vector>
#include <iostream>

using namespace std;

vector<int> answer(2);

void compress(vector<vector<int>>& arr, int x, int y, int size) {
    if (size == 1) {
        answer[arr[x][y]]++;
        return;
    }

    int initial = arr[x][y];
    bool isSame = true;

    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (arr[i][j] != initial) {
                isSame = false;
                break;
            }
        }
        if (!isSame) break;
    }

    if (isSame) {
        answer[initial]++;
    } else {
        int newSize = size / 2;
        compress(arr, x, y, newSize);
        compress(arr, x, y + newSize, newSize);
        compress(arr, x + newSize, y, newSize);
        compress(arr, x + newSize, y + newSize, newSize);
    }
}

vector<int> solution(vector<vector<int>> arr) {
    compress(arr, 0, 0, arr.size());
    return answer;
}