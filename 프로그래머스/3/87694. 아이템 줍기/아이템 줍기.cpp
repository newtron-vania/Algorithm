#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

// 상, 하, 좌, 우 이동을 위한 방향 배열
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY)
{
    int answer = 0;

    // 좌표를 2배로 확장하여 경계 처리를 정밀하게 하기 위함
    characterX *= 2, characterY *= 2, itemX *= 2, itemY *= 2;

    // 110x110 크기의 보드 초기화
    vector<vector<int>> board(110, vector<int>(110));

    // 사각형 정보를 바탕으로 보드에 외곽선을 그림
    for (int i = 0; i < rectangle.size(); i++)
    {
        // 모든 사각형 좌표를 2배 확장
        for (int j = 0; j < rectangle[0].size(); j++)
            rectangle[i][j] = rectangle[i][j] * 2;

        int x1 = rectangle[i][0], y1 = rectangle[i][1];
        int x2 = rectangle[i][2], y2 = rectangle[i][3];

        // 사각형 영역을 1로 채움 (우선 전체 영역)
        for (int y = y1; y <= y2; y++)
            for (int x = x1; x <= x2; x++)
                board[y][x] = 1;
    }

    // 사각형 내부를 0으로 다시 덮어서 외곽만 남기기
    for (int i = 0; i < rectangle.size(); i++)
    {
        int x1 = rectangle[i][0], y1 = rectangle[i][1];
        int x2 = rectangle[i][2], y2 = rectangle[i][3];

        // 사각형 내부만 0으로 설정 (테두리는 제외)
        for (int y = y1 + 1; y < y2; y++)
            for (int x = x1 + 1; x < x2; x++)
                board[y][x] = 0;
    }

    // BFS를 위한 큐 초기화
    queue<pair<int, int>> q;
    q.emplace(characterY, characterX);

    // BFS 시작
    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        // 아이템 위치에 도달하면 종료
        if (y == itemY && x == itemX)
            break;

        // 4방향 탐색
        for (int i = 0; i < 4; i++)
        {
            int nextY = y + dy[i];
            int nextX = x + dx[i];

            // 유효한 경로(외곽선 위)라면
            if (board[nextY][nextX] == 1)
            {
                q.emplace(nextY, nextX);
                // 거리 저장 (현재 칸 + 1)
                board[nextY][nextX] = board[y][x] + 1;
            }
        }
    }

    // 실제 거리 계산 시 좌표를 2배 했으므로 2로 나눔
    answer = board[itemY][itemX] / 2;
    return answer;
}
