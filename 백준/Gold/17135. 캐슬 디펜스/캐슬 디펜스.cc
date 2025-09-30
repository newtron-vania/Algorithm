#include <bits/stdc++.h>

using namespace std;

int N, M, D;
int origin_map[16][16];
int temp_map[16][16]; 
int dx[3] = {0, -1, 0};
int dy[3] = {-1, 0, 1};

struct Enemy
{
    int x, y, dist;
};

int bfs(int sx, int sy)
{
    bool visited[16][16] = {false};
    queue<Enemy> q;
    q.push({sx, sy, 1});
    visited[sx][sy] = true;

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        if (temp_map[cur.x][cur.y] == 1) return cur.y * 100 + cur.x; // (y우선 정렬 위해)

        if (cur.dist == D) continue;

        for (int d = 0; d < 3; d++)
        {
            int nx = cur.x + dx[d];
            int ny = cur.y + dy[d];

            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if (visited[nx][ny]) continue;
            visited[nx][ny] = true;
            q.push({nx, ny, cur.dist + 1});
        }
    }
    return -1;
}

int simulate(vector<int> archers)
{
    memcpy(temp_map, origin_map, sizeof(origin_map));
    int kill = 0;

    for (int turn = 0; turn < N; turn++)
    {
        set<pair<int,int>> targets;

        for (int col : archers)
        {
            int res = bfs(N - 1, col);
            if (res != -1)
            {
                int x = res % 100;
                int y = res / 100;
                targets.insert({x, y});
            }
        }

        for (auto &t : targets)
        {
            if (temp_map[t.first][t.second] == 1)
            {
                temp_map[t.first][t.second] = 0;
                kill++;
            }
        }

        for (int i = N - 1; i > 0; i--)
        {
            for (int j = 0; j < M; j++)
            {
                temp_map[i][j] = temp_map[i - 1][j];
            }
        }
        for (int j = 0; j < M; j++) temp_map[0][j] = 0;
    }

    return kill;
}

int main()
{
    scanf("%d %d %d", &N, &M, &D);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%d", &origin_map[i][j]);
        }
    }

    vector<int> cols(M);
    iota(cols.begin(), cols.end(), 0);

    int ans = 0;
    vector<int> idx(M, 0);
    fill(idx.end() - 3, idx.end(), 1);

    do
    {
        vector<int> archers;
        for (int i = 0; i < M; i++)
        {
            if (idx[i]) archers.push_back(i);
        }
        ans = max(ans, simulate(archers));
    } while (next_permutation(idx.begin(), idx.end()));

    printf("%d\n", ans);
    return 0;
}
