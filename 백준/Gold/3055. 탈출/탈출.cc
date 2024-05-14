#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int r, c;
int d_x, d_y, s_x, s_y;
vector <pair<int, int>> water;
queue<pair<int, int>> s, w;
char forest[51][51];
int s_visited[51][51] = {0, }, w_visited[51][51] = {0, };

void bfs() {
    for(int i = 0 ; i < water.size() ; i++) {
        w.push(make_pair(water[i].first, water[i].second));
        w_visited[water[i].first][water[i].second] = 1;
    }

    s.push(make_pair(s_x, s_y));
    s_visited[s_x][s_y] = 1;

    //종료 조건
        // 1. 고슴도치가 비버의 굴에 도착한 경우 => 거리 출력하고 끝
        // 2. 고슴도치가 더 이상 탐색을 할 수 없는 경우 => KAKTUS 출력하고 끝
    while(!s.empty()) {
        // 물 먼저 이동 (예상 경로)
        int w_size = w.size();

        for(int i = 0 ; i < w_size ; i++) {
            pair<int, int> cur = w.front();
            w.pop();

            for(int j = 0 ; j < 4 ; j++) {
                int nx = dx[j] + cur.first;
                int ny = dy[j] + cur.second;

                if(nx < 0 || ny < 0 || nx >= r || ny >= c || forest[nx][ny] == 'X' || forest[nx][ny] == 'D' || w_visited[nx][ny]) continue;
                w.push(make_pair(nx, ny));
                w_visited[nx][ny] = 1; 
            }
        }

        //고슴도치 이동
        int s_size = s.size();

        for(int i = 0 ; i < s_size ; i++) {
            pair<int, int> cur = s.front();
            s.pop();

            for(int j = 0 ; j < 4 ; j++) {
                int nx = dx[j] + cur.first;
                int ny = dy[j] + cur.second;

                if(nx < 0 || ny < 0 || nx >= r || ny >= c || forest[nx][ny] == 'X' || w_visited[nx][ny] || s_visited[nx][ny]) continue;
                if(forest[nx][ny] == 'D') { // 목적지 도착
                    cout << s_visited[cur.first][cur.second];
                    return;
                }

                s.push(make_pair(nx, ny));
                s_visited[nx][ny] = s_visited[cur.first][cur.second] + 1; 
            }
        }
    }

    cout << "KAKTUS";
    return;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
    cin >> r >> c;

    for(int i = 0 ; i < r ; i++) {
        for(int j = 0 ; j < c ; j++) {
            cin >> forest[i][j];

            if(forest[i][j] == '*') water.push_back(make_pair(i, j)); // 물
            else if(forest[i][j] == 'D') { // 비버
                d_x = i;
                d_y = j;
            }
            else if(forest[i][j] == 'S') { // 고슴도치
                s_x = i;
                s_y = j;
            }
        }
    }

    bfs();

    return 0;
}