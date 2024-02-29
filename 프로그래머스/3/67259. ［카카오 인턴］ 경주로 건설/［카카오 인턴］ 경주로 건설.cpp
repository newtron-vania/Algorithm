#include <iostream>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

const int INF = 987654321;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

struct State 
{
    int x, y, cost, direction;  // 현재 위치 (x, y), 누적 비용 cost, 이전 방향 direction
};

bool operator>(const State& a, const State& b) 
{
    return a.cost > b.cost;
}

int solution(vector<vector<int>> board) 
{
    int answer = -1;
    int N = board.size();
    vector<vector<vector<int>>> dist(N, vector<vector<int>>(N, vector<int>(4, INF)));  // 최소 비용 저장 배열
    priority_queue<State, vector<State>, greater<State>> pq;  // 우선순위 큐

    // 초기값 설정
    pq.push({0, 0, 0, -1});
    for(int i = 0; i < 4; i++)
    {
        dist[0][0][i] = 0;
    }
    

    while (!pq.empty()) {
        State cur = pq.top();
        pq.pop();

        int x = cur.x;
        int y = cur.y;
        int cost = cur.cost;
        int direction = cur.direction;

        for (int i = 0; i < 4; i++) 
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 범위를 벗어나거나 벽인 경우 continue
            if (nx < 0 || ny < 0 || nx >= N || ny >= N || board[nx][ny] == 1)
                continue;
            // 이전 경로와 방향이 반대라면 continue
            if((i + 2) % 4 == direction)
                continue;

            int newCost = cost + 100;  // 직선 도로 비용

            // 방향이 변경되면 코너 비용 추가
            if (direction != -1 && direction != i)
                newCost += 500;

            if (newCost <= dist[nx][ny][i]) 
            {
                dist[nx][ny][i] = newCost;
                pq.push({nx, ny, newCost, i});
            }
        }
    }

    answer = *min_element(dist[N-1][N-1].begin(), dist[N-1][N-1].end());
    
    return answer;
}