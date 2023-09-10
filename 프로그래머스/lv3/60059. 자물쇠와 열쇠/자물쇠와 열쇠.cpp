#include <string>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> rotate(vector<vector<int>>& key) {
    int n = key.size();
    vector<vector<int>> result(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int x = j;
            int y = n - i - 1;
            result[x][y] = key[i][j];
        }
    }
    return result;
}

bool check_open(vector<vector<int>>& key, vector<vector<int>>& lock, int n, int m, int count) {
    for (int x = 0; x < m + n - 1; ++x) {
        for (int y = 0; y < m + n - 1; ++y) {
            bool OK = true;
            int result = 0;

            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    int hx = x - (n - 1 - i);
                    int hy = y - (n - 1 - j);
                    if (hx < 0 || hy < 0 || hx >= m || hy >= m) continue;
                    if (key[i][j] == 1 && lock[hx][hy] == 1) {
                        OK = false;
                        break;
                    } else if (key[i][j] == 1 && lock[hx][hy] == 0) {
                        result += 1;
                    }
                }
                if (!OK) break;
            }
            if (OK && result == count) {
                return true;
            }
        }
    }
    return false;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    int holl_count = 0;
    int n = key.size();
    int m = lock.size();
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            if (lock[i][j] == 0) {
                holl_count += 1;
            }
        }
    }

    bool answer = false;
    for (int i = 0; i < 4; ++i) {
        answer = check_open(key, lock, n, m, holl_count);
        if (answer) {
            break;
        }
        key = rotate(key);
    }

    return answer;
}




