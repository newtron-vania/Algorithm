#include <bits/stdc++.h>
using namespace std;

struct Shark 
{
    int r, c, s, d, z;

    Shark(int r, int c, int s, int d, int z) 
        : r(r), c(c), s(s), d(d), z(z) {}
};

int R, C, M;
vector<vector<Shark*>> graph;
int answer = 0;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> R >> C >> M;

    graph = vector<vector<Shark*>>(R, vector<Shark*>(C, nullptr));

    for (int i = 0; i < M; i++) 
    {
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;

        r--; c--;

        if (d == 1) d = 0;
        else if (d == 2) d = 2;
        else if (d == 3) d = 3;
        else if (d == 4) d = 1;

        graph[r][c] = new Shark(r, c, s, d, z);
    }

    for (int col = 0; col < C; col++) 
    {
        // 가장 가까운 상어 잡기
        for (int row = 0; row < R; row++) 
        {
            if (graph[row][col] != nullptr) 
            {
                answer += graph[row][col]->z;
                delete graph[row][col];
                graph[row][col] = nullptr;
                break;
            }
        }

        // 상어 이동
        queue<Shark*> q;
        for (int i = 0; i < R; i++) 
        {
            for (int j = 0; j < C; j++) 
            {
                if (graph[i][j] != nullptr) 
                {
                    q.push(new Shark(*graph[i][j]));
                    delete graph[i][j];
                    graph[i][j] = nullptr;
                }
            }
        }

        // 새로운 낚시판
        graph = vector<vector<Shark*>>(R, vector<Shark*>(C, nullptr));

        while (!q.empty()) 
        {
            Shark* sm = q.front(); q.pop();
            int speed = sm->s;

            if (sm->d == 0 || sm->d == 2)
                speed %= (R - 1) * 2;
            else
                speed %= (C - 1) * 2;

            for (int s = 0; s < speed; s++) 
            {
                int newR = sm->r + dx[sm->d];
                int newC = sm->c + dy[sm->d];

                if (newR < 0 || newR >= R || newC < 0 || newC >= C) 
                {
                    sm->d = (sm->d + 2) % 4;
                    newR = sm->r + dx[sm->d];
                    newC = sm->c + dy[sm->d];
                }

                sm->r = newR;
                sm->c = newC;
            }

            // 격자에 상어 놓기 (기존보다 크면 덮어쓰기)
            if (graph[sm->r][sm->c] == nullptr || graph[sm->r][sm->c]->z < sm->z) 
            {
                if (graph[sm->r][sm->c] != nullptr) delete graph[sm->r][sm->c];
                graph[sm->r][sm->c] = sm;
            } 
            else 
            {
                delete sm;
            }
        }
    }

    cout << answer << '\n';
    return 0;
}
