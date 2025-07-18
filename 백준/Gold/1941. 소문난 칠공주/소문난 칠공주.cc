#include <bits/stdc++.h>

using namespace std;

char board[5][5];
bool visited[25];
int answer = 0;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

// 선택된 7개의 위치를 저장하고, 인접한지 체크
bool isConnected(const vector<int>& pos)
{
    queue<int> q;
    bool vis[5][5] = { false };
    int cnt = 1;

    int x = pos[0] / 5;
    int y = pos[0] % 5;
    vis[x][y] = true;
    q.push(pos[0]);

    while (!q.empty()) 
    {
        int cur = q.front(); q.pop();
        int cx = cur / 5, cy = cur % 5;
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];
            int nid = nx * 5 + ny;
            
            if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;
            if (find(pos.begin(), pos.end(), nid) == pos.end()) continue;
            if (vis[nx][ny]) continue;
            
            vis[nx][ny] = true;
            q.push(nid);
            cnt++;
        }
    }
    return cnt == 7;
}

// 선정한 7개 좌표가 연결되어있고, 4개 이상일 경우를 확인
void dfs(int idx, int cnt, int scnt, vector<int>& pos)
{
    if (cnt == 7)
    {
        if (scnt >= 4 && isConnected(pos))
        {
            answer++;
        }
        return;
    }
    for (int i = idx; i < 25; i++)
    {
        if (visited[i]) continue;
        
        visited[i] = true;
        pos.push_back(i);
        int x = i / 5;
        int y = i % 5;
        
        dfs(i + 1, cnt + 1, scnt + (board[x][y] == 'S' ? 1 : 0), pos);
        
        pos.pop_back();
        visited[i] = false;
    }
}

int main() 
{
    for (int i = 0; i < 5; i++)
    {
        cin >> board[i];
    }
    
    vector<int> pos;
    dfs(0, 0, 0, pos);

    cout << answer << '\n';
    return 0;
}