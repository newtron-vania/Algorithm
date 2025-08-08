#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    int weight[101], value[101];
    for (int i = 0; i < N; i++)
    {
        cin >> weight[i] >> value[i];
    }

    int bag[101][100001];
    fill(&bag[0][0], &bag[0][0] + 101 * 100001, 0);

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= K; j++)
        {
            if (weight[i - 1] > j)
            {
                bag[i][j] = bag[i - 1][j];
            }
            else
            {
                bag[i][j] = max(bag[i - 1][j], value[i - 1] + bag[i - 1][j - weight[i - 1]]);
            }
        }
    }

    cout << bag[N][K];
    return 0;
}
