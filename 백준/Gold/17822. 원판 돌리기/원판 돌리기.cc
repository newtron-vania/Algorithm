#include <bits/stdc++.h>
using namespace std;

int N, M, T;
int arr[52][52];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void rotateClock(int row, int k)
{
    deque<int> dq;
    for (int i = 1; i <= M; i++)
        dq.push_back(arr[row][i]);

    for (int i = 0; i < k; i++)
    {
        dq.push_front(dq.back());
        dq.pop_back();
    }

    for (int i = 1; i <= M; i++)
    {
        arr[row][i] = dq.front();
        dq.pop_front();
    }
}

void rotate(int x, int d, int k)
{
    for (int i = 1; i <= N; i++)
    {
        if (i % x == 0)
        {
            if (d == 0) rotateClock(i, k);
            else rotateClock(i, M - k);
        }
    }
}

double getMeans()
{
    int cnt = 0;
    double sum = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if (arr[i][j] > 0) cnt++;
            sum += arr[i][j];
        }
    }
    if (cnt == 0) return 0;
    return sum / cnt;
}

void plusMinus()
{
    double standard = getMeans();
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if (arr[i][j] == 0) continue;
            if (arr[i][j] > standard) arr[i][j]--;
            else if (arr[i][j] < standard) arr[i][j]++;
        }
    }
}

void getAdjacentPoint()
{
    vector<pair<int, int>> points;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if (arr[i][j] == 0) continue;
            for (int k = 0; k < 4; k++)
            {
                int nx = i + dx[k];
                int ny = j + dy[k];

                if (nx < 1 || nx > N) continue;
                if (ny > M) ny = 1;
                else if (ny < 1) ny = M;

                if (arr[i][j] == arr[nx][ny])
                {
                    points.push_back({i, j});
                    points.push_back({nx, ny});
                }
            }
        }
    }

    if (!points.empty())
    {
        for (auto& p : points)
            arr[p.first][p.second] = 0;
    }
    else
    {
        plusMinus();
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> T;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int t = 0; t < T; t++)
    {
        int x, d, k;
        cin >> x >> d >> k;
        rotate(x, d, k);
        getAdjacentPoint();
    }

    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            ans += arr[i][j];
        }
    }

    cout << ans << '\n';
    return 0;
}
