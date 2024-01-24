#include <string>
#include <vector>
#include <algorithm>


using namespace std;

const int MAX = 500;

int r, c;
bool visited[MAX][MAX][4];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int getLengthOfCycle(int x, int y, int dir, vector<string> grid) {
    int cnt = 0;
    
    while (visited[x][y][dir] == false) {
        cnt += 1;
        visited[x][y][dir] = true;
        
        if (grid[x][y] == 'L') {
            dir = (dir + 3) % 4;
        } else if (grid[x][y] == 'R') {
            dir = (dir + 1) % 4;
        }
        
        // 격자 범위 내의 값으로 갱신
        x = (x + dx[dir] + r) % r;
        y = (y + dy[dir] + c) % c;
    }
    
    return cnt;
}

vector<int> solution(vector<string> grid) {
    vector<int> answer;
    r = grid.size();
    c = grid[0].size();
    
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            for (int k=0; k<4; k++) {
                if (!visited[i][j][k]) {
                    answer.push_back(getLengthOfCycle(i, j, k, grid));
                }
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}