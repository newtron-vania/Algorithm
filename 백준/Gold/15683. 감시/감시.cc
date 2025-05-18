#include <bits/stdc++.h>
using namespace std;

const int DX[4] = {1, 0, -1, 0};
const int DY[4] = {0, 1, 0, -1};

int n, m;
int board1[10][10]; // 최초에 입력받은 board를 저장할 변수
int board2[10][10]; // 사각 지대의 개수를 세기 위해 사용할 변수
vector<pair<int, int>> cctv; // cctv의 좌표를 저장할 변수

bool IsValid(int a, int b)
{
    return a < 0 || a >= n || b < 0 || b >= m;
}

// (x, y)에서 dir 방향으로 진행하면서 벽을 만날 때까지 지나치는 모든 빈칸을 7로 바꿈
void ScanCCTV(int x, int y, int dir)
{
    dir %= 4;
    while (true)
    {
        x += DX[dir];
        y += DY[dir];
        if (IsValid(x, y) || board2[x][y] == 6)
            return;
        if (board2[x][y] != 0)
            continue;
        board2[x][y] = 7;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    int mn = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board1[i][j];
            if (board1[i][j] != 0 && board1[i][j] != 6)
                cctv.push_back({i, j});
            if (board1[i][j] == 0)
                mn++;
        }
    }

    for (int tmp = 0; tmp < (1 << (2 * cctv.size())); tmp++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                board2[i][j] = board1[i][j];
            }
        }

        int brute = tmp;
        for (int i = 0; i < cctv.size(); i++)
        {
            int dir = brute % 4;
            brute /= 4;
            int x = cctv[i].first;
            int y = cctv[i].second;

            if (board1[x][y] == 1)
            {
                ScanCCTV(x, y, dir);
            }
            else if (board1[x][y] == 2)
            {
                ScanCCTV(x, y, dir);
                ScanCCTV(x, y, dir + 2);
            }
            else if (board1[x][y] == 3)
            {
                ScanCCTV(x, y, dir);
                ScanCCTV(x, y, dir + 1);
            }
            else if (board1[x][y] == 4)
            {
                ScanCCTV(x, y, dir);
                ScanCCTV(x, y, dir + 1);
                ScanCCTV(x, y, dir + 2);
            }
            else
            {
                ScanCCTV(x, y, dir);
                ScanCCTV(x, y, dir + 1);
                ScanCCTV(x, y, dir + 2);
                ScanCCTV(x, y, dir + 3);
            }
        }

        int val = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                val += (board2[i][j] == 0);
            }
        }

        mn = min(mn, val);
    }

    cout << mn;
}
