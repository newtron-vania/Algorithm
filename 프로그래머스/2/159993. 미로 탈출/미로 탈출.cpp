#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

struct Node {
    int row, col, cost, heuristic;

    Node(int r, int c, int cst, int h) : row(r), col(c), cost(cst), heuristic(h) {}

    bool operator>(const Node& other) const {
        return cost + heuristic > other.cost + other.heuristic;
    }
};

int calculateHeuristic(int currentRow, int currentCol, int targetRow, int targetCol) {
    return abs(targetRow - currentRow) + abs(targetCol - currentCol);
}

int AStar(const vector<string>& maps, int startRow, int startCol, int targetRow, int targetCol) {
    int rows = maps.size();
    int cols = maps[0].size();

    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    priority_queue<Node, vector<Node>, greater<Node>> pq;

    // 방향 설정
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};
    

    // 시작 노드를 우선순위 큐에 넣기
    pq.push(Node(startRow, startCol, 0, calculateHeuristic(startRow, startCol, targetRow, targetCol)));

    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();

        int r = current.row;
        int c = current.col;

        if (r == targetRow && c == targetCol) {
            // 출구에 도달
            return current.cost;
        }
        
        if (!visited[r][c]) {
            visited[r][c] = true;

            //주변 노드 확인
            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && maps[nr][nc] != 'X' && !visited[nr][nc]) {
                    int newCost = current.cost + 1;
                    int heuristic = calculateHeuristic(nr, nc, targetRow, targetCol);
                    pq.push(Node(nr, nc, newCost, heuristic));
                }
            }
        }
    }

    // 우선순위 큐가 비어있고 출구에 도달하지 않았다면 유효한 경로가 없음
    return -1;
}

int solution(vector<string> maps)
{
    int answer = 0;
    
    int rows = maps.size();
    int cols = maps[0].size();
    
    int startRow, startCol, endRow, endCol, leverRow, leverCol;

    // 시작 지점, 출구 및 레버의 위치를 찾기
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (maps[i][j] == 'S') {
                startRow = i;
                startCol = j;
            } else if (maps[i][j] == 'E') {
                endRow = i;
                endCol = j;
            } else if (maps[i][j] == 'L') {
                leverRow = i;
                leverCol = j;
            }
        }
    }
    int cost = 0;
    cost = AStar(maps, startRow, startCol, leverRow, leverCol);
    if(cost < 0)
        return -1;
    answer += cost;
    cost = AStar(maps, leverRow, leverCol, endRow, endCol);
    if(cost < 0)
        return -1;
    answer += cost;
    return answer;
}

