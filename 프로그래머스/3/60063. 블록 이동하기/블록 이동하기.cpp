#include <iostream>
#include <vector>
#include <deque>

using namespace std;

// 방향 정의
const int dx[] = {0, 1, -1, 0};
const int dy[] = {1, 0, 0, -1};

// 회전 방향 정의
const int rot[2][5][2] = {
    {{0, 0}, {0, 0}, {0, 1}, {-1, 0}, {-1, 1}},
    {{0, 0}, {0, 0}, {1, 0}, {0, -1}, {1, -1}}
};

struct State {
    int count, x1, y1, d;
};

int solution(vector<vector<int>> board) {
    int n = board.size();
    int answer = 0;

    // 방문 여부 및 방향에 따른 상태 저장
    vector<vector<vector<int>>> visited(n, vector<vector<int>>(n, vector<int>(2, 0)));

    // count, x1, y1, d
    deque<State> q;
    q.push_back({0, 0, 0, 0});

    while (!q.empty()) {
        auto [count, x1, y1, d] = q.front();
        q.pop_front();

        int x2 = x1 + dx[d];
        int y2 = y1 + dy[d];


        if ((x1 == n - 1 && y1 == n - 1) || (x2 == n - 1 && y2 == n - 1)) {
            answer = count;
            break;
        }

        for (int k = 0; k < 4; ++k) {
            int hx1 = x1 + dx[k];
            int hy1 = y1 + dy[k];
            int hx2 = x2 + dx[k];
            int hy2 = y2 + dy[k];

            if (hx1 >= 0 && hx1 < n && hy1 >= 0 && hy1 < n && hx2 >= 0 && hx2 < n && hy2 >= 0 && hy2 < n) {
                if (board[hx1][hy1] == 0 && board[hx2][hy2] == 0) {
                    //회전X의 경우 : 이동 방향에 벽이 없고 현재 회전방향 상태로 방문한 적이 없다면 추가
                    if(visited[hx1][hy1][d] == 0)
                    {
                        visited[hx1][hy1][d] = 1;
                        q.push_back({count+1, hx1, hy1, d});
                    }
                        
                    //회전O의 경우
                    //가로방향이고 세로축 이동이고 그 방향에 벽이 없다면 해당 방향으로 회전하고 방문 확인
                    if(dx[k] != 0 && d == 0){
                        //dx[k]>0 : 1, 2 | dx[k] <0 : -1, -2
                        int nd = 1;
                        for(int i = 1; i < 3; i++){
                            int next = dx[k] >= 0 ? i * dx[k] : 5 + i * dx[k];
                            int hx = x1 + rot[d][next][0];
                            int hy = y1 + rot[d][next][1];
                            if(visited[hx][hy][nd] == 0){
                                visited[hx][hy][nd] = 1;
                                q.push_back({count+1, hx, hy, nd});
                            }
                        }
                    }
                    //세로방향이고 가로축 이동이고 그 방향에 벽이 없다면 해당 방향으로 회전하고 방문 확인
                    else if(dy[k] != 0 && d == 1)
                    {
                        int nd = 0;
                        for(int i = 1; i < 3; i++)
                        {
                            int next = dy[k] >= 0 ? i * dy[k] : 5 + i * dy[k];
                            int hx = x1 + rot[d][next][0];
                            int hy = y1 + rot[d][next][1];
                            if(visited[hx][hy][nd] == 0)
                            {
                                visited[hx][hy][nd] = 1;
                                q.push_back({count+1, hx, hy, nd});
                            }
                        }
                    }
                }
            }
        }
    }

    return answer;
}