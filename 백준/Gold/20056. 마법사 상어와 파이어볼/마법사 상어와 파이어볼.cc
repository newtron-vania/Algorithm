#include <bits/stdc++.h>

using namespace std;

const int MAX = 55;

struct FireBall
{
    int x;
    int y;
    int massive;
    int speed;
    int dir;
};

int dx[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int T_Dir[] = { 0, 2, 4, 6 };
int F_Dir[] = { 1, 3, 5, 7 };

int N, M, K;
vector<FireBall> graph[MAX][MAX];
vector<FireBall> fireBallList;

void MoveFireBall()
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            graph[i][j].clear();
        }
    }

    for (int i = 0; i < fireBallList.size(); i++)
    {
        int x = fireBallList[i].x;
        int y = fireBallList[i].y;
        int mass = fireBallList[i].massive;
        int speed = fireBallList[i].speed;
        int dir = fireBallList[i].dir;

        int move = speed % N;
        int nx = x + dx[dir] * move;
        int ny = y + dy[dir] * move;

        if (nx > N) nx -= N;
        if (ny > N) ny -= N;
        if (nx < 1) nx += N;
        if (ny < 1) ny += N;

        graph[nx][ny].push_back({ nx, ny, mass, speed, dir });
        fireBallList[i].x = nx;
        fireBallList[i].y = ny;
    }
}

void SumFireBall()
{
    vector<FireBall> temp;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (graph[i][j].empty()) continue;

            if (graph[i][j].size() == 1)
            {
                temp.push_back(graph[i][j][0]);
                continue;
            }

            int totalMass = 0;
            int totalSpeed = 0;
            int count = graph[i][j].size();
            bool allEven = true, allOdd = true;

            for (const auto& fb : graph[i][j])
            {
                totalMass += fb.massive;
                totalSpeed += fb.speed;
                if (fb.dir % 2 == 0) allOdd = false;
                else allEven = false;
            }

            int newMass = totalMass / 5;
            int newSpeed = totalSpeed / count;
            if (newMass == 0) continue;

            const int* dirs = (allEven || allOdd) ? T_Dir : F_Dir;
            for (int d = 0; d < 4; d++)
            {
                temp.push_back({ i, j, newMass, newSpeed, dirs[d] });
            }
        }
    }
    fireBallList = temp;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> K;
    for (int i = 0; i < M; i++)
    {
        int r, c, m, s, d;
        cin >> r >> c >> m >> s >> d;
        fireBallList.push_back({ r, c, m, s, d });
        graph[r][c].push_back({ r, c, m, s, d });
    }

    for (int i = 0; i < K; i++)
    {
        MoveFireBall();
        SumFireBall();
    }

    int answer = 0;
    for (FireBall fb : fireBallList)
    {
        answer += fb.massive;
    }

    cout << answer << '\n';
    return 0;
}
