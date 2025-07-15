#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<string> board;
vector<vector<int>> dp;
vector<vector<bool>> visited;
int dy[4] = {-1, 1, 0, 0};  // 상하좌우
int dx[4] = {0, 0, -1, 1};
bool infinite = false;

int dfs(int y, int x)
{
    if (y < 0 || x < 0 || y >= N || x >= M || board[y][x] == 'H') return 0;
    if (visited[y][x])
    {
        infinite = true;
        return 0;
    }
    if (dp[y][x] != -1) return dp[y][x];

    visited[y][x] = true;
    int max_move = 0;
    int jump = board[y][x] - '0';

    for (int dir = 0; dir < 4; dir++)
    {
        int ny = y + dy[dir] * jump;
        int nx = x + dx[dir] * jump;
        max_move = max(max_move, dfs(ny, nx) + 1);
    }

    visited[y][x] = false;
    dp[y][x] = max_move;
    return max_move;
}

int main() 
{
    cin >> N >> M;
    board.resize(N);
    dp.assign(N, vector<int>(M, -1));
    visited.assign(N, vector<bool>(M, false));

    for (int i = 0; i < N; ++i) 
    {
        cin >> board[i];
    }

    int result = dfs(0, 0);
    if (infinite) cout << -1 << '\n';
    else cout << result << '\n';

    return 0;
}
