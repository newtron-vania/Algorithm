#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int x, y, dir, mirror;
};

const int INF = 1e9;
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

int main()
{
    int w, h;
    scanf("%d %d", &w, &h);

    vector<string> board(h);
    for (int i = 0; i < h; i++)
    {
        char s[101];
        scanf("%s", s);
        board[i] = s;
    }

    vector<pair<int, int>> points;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (board[i][j] == 'C')
            {
                points.push_back({i, j});
            }
        }
    }

    int sx = points[0].first, sy = points[0].second;
    int ex = points[1].first, ey = points[1].second;

    int dist[101][101][4];
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            for (int d = 0; d < 4; d++)
            {
                dist[i][j][d] = INF;
            }
        }
    }

    queue<Node> q;
    for (int d = 0; d < 4; d++)
    {
        dist[sx][sy][d] = 0;
        q.push({sx, sy, d, 0});
    }

    while (!q.empty())
    {
        Node cur = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];

            if (nx < 0 || ny < 0 || nx >= h || ny >= w)
            {
                continue;
            }
            if (board[nx][ny] == '*')
            {
                continue;
            }

            int cost = cur.mirror + (cur.dir != dir);
            if (dist[nx][ny][dir] > cost)
            {
                dist[nx][ny][dir] = cost;
                q.push({nx, ny, dir, cost});
            }
        }
    }

    int ans = INF;
    for (int d = 0; d < 4; d++)
    {
        ans = min(ans, dist[ex][ey][d]);
    }

    printf("%d\n", ans);
    return 0;
}
