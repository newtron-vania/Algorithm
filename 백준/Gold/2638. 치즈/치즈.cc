#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// 방향 벡터
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// 공기 탐색
void air_bfs(int i, int j, vector<vector<int>>& visited, vector<vector<int>>& real_graph, int n, int m) 
{
    queue<pair<int, int>> q;
    q.push({i, j});
    visited[i][j] = 1;

    while (!q.empty()) 
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int k = 0; k < 4; ++k) 
        {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) 
            {
                // 다음 진행이 공기면 (큐 추가, 방문처리)
                if (visited[nx][ny] == 0 && real_graph[nx][ny] == 0) 
                {
                    q.push({nx, ny});
                    visited[nx][ny] = 1;
                }
                // 다음 진행이 치즈면 (방문정보 업데이트)
                else if (real_graph[nx][ny] == 1) 
                {
                    visited[nx][ny] += 1;
                }
            }
        }
    }
}

int main() 
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> real_graph(n, vector<int>(m));
    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < m; ++j) 
        {
            cin >> real_graph[i][j];
        }
    }

    int time = 0;

    while (true) 
    {
        vector<vector<int>> visited(n, vector<int>(m, 0));

        air_bfs(0, 0, visited, real_graph, n, m);
        // 탐색 한바퀴 끝나면 시간+1
        time += 1;

        // 두 면 이상 공기랑 닿으면, 빈칸 처리
        for (int i = 0; i < n; ++i) 
        {
            for (int j = 0; j < m; ++j) 
            {
                if (visited[i][j] >= 2) 
                {
                    real_graph[i][j] = 0;
                }
            }
        }

        // 공기 카운트
        int block_cnt = 0;
        for (int i = 0; i < n; ++i) 
        {
            for (int j = 0; j < m; ++j) 
            {
                if (real_graph[i][j] == 0) 
                {
                    block_cnt += 1;
                }
            }
        }
        // 탐색 한번 하고 난 그래프의 공기수가 배열의 크기랑 같으면 break
        if (block_cnt == (n * m)) 
        {
            break;
        }
    }

    cout << time << endl;

    return 0;
}
