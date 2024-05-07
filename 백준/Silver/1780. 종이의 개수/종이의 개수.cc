#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<int>> square;
array<int, 3> ans = {0, 0, 0};

void find_square(int x, int y, int n)
{
    int bit = square[x][y];
    for (int i = x; i < x + n; ++i)
    {
        for (int j = y; j < y + n; ++j)
        {
            if (bit != square[i][j])
            {
                find_square(x, y, n / 3);
                find_square(x, y + n / 3, n / 3);
                find_square(x, y + n / 3 * 2, n / 3);
                find_square(x + n / 3, y, n / 3);
                find_square(x + n / 3, y + n / 3, n / 3);
                find_square(x + n / 3, y + n / 3 * 2, n / 3);
                find_square(x + n / 3 * 2, y, n / 3);
                find_square(x + n / 3 * 2, y + n / 3, n / 3);
                find_square(x + n / 3 * 2, y + n / 3 * 2, n / 3);
                return;
            }
        }
    }
    if (bit == 0)
    {
        ans[0]++;
    }
    else if (bit == 1)
    {
        ans[1]++;
    }
    else
    {
        ans[-1]++;
    }
}

int main()
{
    cin >> N;
    square.resize(N, vector<int>(N));
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> square[i][j];
        }
    }
    find_square(0, 0, N);
    cout << ans[-1] << "\n" << ans[0] << "\n" << ans[1] << endl;
    return 0;
}
