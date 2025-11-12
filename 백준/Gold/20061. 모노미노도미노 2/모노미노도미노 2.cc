#include <bits/stdc++.h>

using namespace std;

int green[6][4]; // 초록 보드 (6행 4열) : 아래로 떨어짐
int blue[4][6];  // 파랑 보드 (4행 6열) : 오른쪽으로 떨어짐

int N;
int score = 0;

// 초록 보드에 블록을 떨어뜨리는 함수
void dropGreen(vector<pair<int,int>> cells)
{
    while (true)
    {
        bool can = true;
        for (auto &p : cells)
        {
            int nr = p.first + 1;
            int nc = p.second;
            if (nr >= 6 || green[nr][nc] == 1)
            {
                can = false;
                break;
            }
        }
        if (!can) break;
        for (auto &p : cells) p.first++;
    }

    for (auto &p : cells) green[p.first][p.second] = 1;
}

// 파랑 보드에 블록을 떨어뜨리는 함수
void dropBlue(vector<pair<int,int>> cells)
{
    while (true)
    {
        bool can = true;
        for (auto &p : cells)
        {
            int nr = p.first;
            int nc = p.second + 1;
            if (nc >= 6 || blue[nr][nc] == 1)
            {
                can = false;
                break;
            }
        }
        if (!can) break;
        for (auto &p : cells) p.second++;
    }

    for (auto &p : cells) blue[p.first][p.second] = 1;
}

// 초록 보드에서 꽉 찬 행을 지우고 점수를 추가하는 함수
void scoreGreen()
{
    while (true)
    {
        int fullRow = -1;
        for (int r = 5; r >= 2; r--)
        {
            bool full = true;
            for (int c = 0; c < 4; c++)
            {
                if (green[r][c] == 0)
                {
                    full = false;
                    break;
                }
            }
            if (full)
            {
                fullRow = r;
                break;
            }
        }
        if (fullRow == -1) break;

        score++;

        // 꽉 찬 행을 제거하고 위쪽 행을 한 칸씩 내림
        for (int r = fullRow; r >= 1; r--)
        {
            for (int c = 0; c < 4; c++)
            {
                green[r][c] = green[r - 1][c];
            }
        }
        // 맨 위 행은 비움
        for (int c = 0; c < 4; c++) green[0][c] = 0;
    }
}

// 파랑 보드에서 꽉 찬 열을 지우고 점수를 추가하는 함수
void scoreBlue()
{
    while (true)
    {
        int fullCol = -1;
        for (int c = 5; c >= 2; c--)
        {
            bool full = true;
            for (int r = 0; r < 4; r++)
            {
                if (blue[r][c] == 0)
                {
                    full = false;
                    break;
                }
            }
            if (full)
            {
                fullCol = c;
                break;
            }
        }
        if (fullCol == -1) break;

        score++;

        // 꽉 찬 열을 제거하고 왼쪽 열들을 오른쪽으로 한 칸씩 이동
        for (int c = fullCol; c >= 1; c--)
        {
            for (int r = 0; r < 4; r++)
            {
                blue[r][c] = blue[r][c - 1];
            }
        }
        // 가장 왼쪽 열은 비움
        for (int r = 0; r < 4; r++) blue[r][0] = 0;
    }
}

// 초록 보드의 연한 구역(0,1행)을 확인하고 블록이 있으면 그 수만큼 아래 행 제거
void handleGreenLight()
{
    int cnt = 0;
    if (green[0][0] || green[0][1] || green[0][2] || green[0][3]) cnt++;
    if (green[1][0] || green[1][1] || green[1][2] || green[1][3]) cnt++;

    while (cnt--)
    {
        // 맨 아래 행(5행)을 제거하고 전체를 한 칸씩 아래로 이동
        for (int r = 5; r >= 1; r--)
        {
            for (int c = 0; c < 4; c++)
            {
                green[r][c] = green[r - 1][c];
            }
        }
        for (int c = 0; c < 4; c++) green[0][c] = 0;
    }
}

// 파랑 보드의 연한 구역(0,1열)을 확인하고 블록이 있으면 그 수만큼 오른쪽 열 제거
void handleBlueLight()
{
    int cnt = 0;

    // 0열에 블록이 있는지 확인
    for (int r = 0; r < 4; r++)
    {
        if (blue[r][0])
        {
            cnt++;
            break;
        }
    }

    // 1열에 블록이 있는지 확인
    for (int r = 0; r < 4; r++)
    {
        if (blue[r][1])
        {
            cnt++;
            break;
        }
    }

    while (cnt--)
    {
        // 맨 오른쪽 열(5열)을 제거하고 전체를 오른쪽으로 한 칸씩 이동
        for (int c = 5; c >= 1; c--)
        {
            for (int r = 0; r < 4; r++)
            {
                blue[r][c] = blue[r][c - 1];
            }
        }
        for (int r = 0; r < 4; r++) blue[r][0] = 0;
    }
}

int main()
{
    scanf("%d", &N);

    memset(green, 0, sizeof(green));
    memset(blue, 0, sizeof(blue));

    for (int i = 0; i < N; i++)
    {
        int t, x, y;
        scanf("%d %d %d", &t, &x, &y);

        // --- 초록 보드 처리 ---
        {
            vector<pair<int,int>> cells;
            if (t == 1)
            {
                // 1x1 블록
                cells.push_back({0, y});
            }
            else if (t == 2)
            {
                // 가로 1x2 블록
                cells.push_back({0, y});
                cells.push_back({0, y + 1});
            }
            else
            {
                // 세로 2x1 블록
                cells.push_back({0, y});
                cells.push_back({1, y});
            }
            dropGreen(cells);
        }

        // --- 파랑 보드 처리 ---
        {
            vector<pair<int,int>> cells;
            if (t == 1)
            {
                // 1x1 블록
                cells.push_back({x, 0});
            }
            else if (t == 2)
            {
                // 가로 1x2 블록 → 파랑에서는 같은 행의 0,1열 차지
                cells.push_back({x, 0});
                cells.push_back({x, 1});
            }
            else
            {
                // 세로 2x1 블록 → 파랑에서는 같은 열의 x,x+1행 차지
                cells.push_back({x, 0});
                cells.push_back({x + 1, 0});
            }
            dropBlue(cells);
        }

        // 점수 계산 및 특수칸 처리
        scoreGreen();
        scoreBlue();
        handleGreenLight();
        handleBlueLight();
    }

    // 남은 블록 수 계산
    int remain = 0;
    for (int r = 0; r < 6; r++)
    {
        for (int c = 0; c < 4; c++)
        {
            if (green[r][c]) remain++;
        }
    }
    for (int r = 0; r < 4; r++)
    {
        for (int c = 0; c < 6; c++)
        {
            if (blue[r][c]) remain++;
        }
    }

    printf("%d\n%d\n", score, remain);
    return 0;
}
