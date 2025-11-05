#include <bits/stdc++.h>

using namespace std;

int N;
int guilty[16];
int R[16][16];
bool dead[16];
int mafia;
int answer = 0;

void dfs(int alive, int night, int current)
{
    if (dead[mafia] || alive == 1)
    {
        answer = max(answer, night);
        return;
    }

    if (alive % 2 == 0)
    {
        // 밤 (마피아가 누구를 죽일지 선택)
        for (int i = 0; i < N; i++)
        {
            if (dead[i] || i == mafia) continue;

            dead[i] = true;

            for (int j = 0; j < N; j++)
            {
                if (!dead[j])
                {
                    guilty[j] += R[i][j];
                }
            }

            dfs(alive - 1, night + 1, current + 1);

            for (int j = 0; j < N; j++)
            {
                if (!dead[j])
                {
                    guilty[j] -= R[i][j];
                }
            }

            dead[i] = false;
        }
    }
    else
    {
        // 낮 (가장 유죄 지수가 높은 사람을 투표로 제거)
        int target = -1, maxGuilt = -1;

        for (int i = 0; i < N; i++)
        {
            if (!dead[i] && guilty[i] > maxGuilt)
            {
                maxGuilt = guilty[i];
                target = i;
            }
        }

        dead[target] = true;
        dfs(alive - 1, night, current);
        dead[target] = false;
    }
}

int main()
{
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &guilty[i]);
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &R[i][j]);
        }
    }

    scanf("%d", &mafia);

    dfs(N, 0, 0);

    printf("%d\n", answer);

    return 0;
}
