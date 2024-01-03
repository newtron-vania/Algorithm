#include <vector>

using namespace std;

int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};// 북동남서
int cnt, target;

void dfs(int i, int j, vector<vector<bool>>& vis, vector<vector<int>>& picture) {
    vis[i][j] = true;// 방문 체크
    cnt++;// 영역++
    for (int dir = 0; dir<4; dir++) 
    {
        int nx = i + dx[dir], ny = j + dy[dir];
        if (nx < 0 || ny < 0 || nx >= vis.size() || ny >= vis[0].size()) continue;
        if (vis[nx][ny] || picture[nx][ny] != target) continue;
        dfs(nx, ny, vis, picture);
    }
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int row = picture.size(), col = picture[0].size();
    vector<int> answer(2, 0);
    vector<vector<bool>> vis(row, vector<bool>(col, false));
    
    for (int i=0; i<row; i++) 
    {
        for (int j=0; j<col; j++) 
        {
            if (!vis[i][j] && picture[i][j]) 
            {
                answer[0]++;
                cnt = 0; target = picture[i][j];
                dfs(i, j, vis, picture);
                answer[1] = max(answer[1], cnt);
            }
        }
    }
    
    return answer;
}