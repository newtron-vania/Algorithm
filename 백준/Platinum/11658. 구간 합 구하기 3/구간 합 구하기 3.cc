#include <bits/stdc++.h>
using namespace std;

const int MAX = 1025;
int N, M;
long long tree[MAX][MAX];
long long arr[MAX][MAX];

// 2D Fenwick Tree 업데이트
inline void update(int y, int x, long long diff)
{
    for (int i = y; i <= N; i += (i & -i))
    {
        for (int j = x; j <= N; j += (j & -j))
        {
            tree[i][j] += diff;
        }
    }
}

// (1,1) ~ (y,x) 까지의 누적 합
inline long long query(int y, int x)
{
    long long res = 0;
    for (int i = y; i > 0; i -= (i & -i))
    {
        for (int j = x; j > 0; j -= (j & -j))
        {
            res += tree[i][j];
        }
    }
    return res;
}

// 구간합
inline long long range_sum(int y1, int x1, int y2, int x2)
{
    return query(y2, x2) - query(y1 - 1, x2) - query(y2, x1 - 1) + query(y1 - 1, x1 - 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    // 초기화
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> arr[i][j];
            update(i, j, arr[i][j]);
        }
    }

    string output;
    output.reserve(M * 20); // 출력 버퍼 미리 확보

    while (M--)
    {
        int cmd;
        cin >> cmd;

        if (cmd == 0) // update (문제 명령 체계에 맞춰)
        {
            int y, x;
            long long c;
            cin >> y >> x >> c;

            long long diff = c - arr[y][x];
            arr[y][x] = c;
            update(y, x, diff);
        }
        else if (cmd == 1) // query
        {
            int y1, x1, y2, x2;
            cin >> y1 >> x1 >> y2 >> x2;

            long long res = range_sum(y1, x1, y2, x2);
            output += to_string(res) + '\n';
        }
    }

    cout << output;
    return 0;
}
