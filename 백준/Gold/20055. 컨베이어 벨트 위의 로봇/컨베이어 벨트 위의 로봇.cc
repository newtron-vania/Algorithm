#include <bits/stdc++.h>

using namespace std;

int N, K, step;
deque<int> naegu;
deque<bool> conveyer;

void rotate()
{
    naegu.push_front(naegu.back());
    naegu.pop_back();

    conveyer.push_front(conveyer.back());
    conveyer.pop_back();

    conveyer[N - 1] = false;
}

void move()
{
    for (int i = N - 2; i >= 0; i--)
    {
        if (!conveyer[i + 1] && naegu[i + 1] > 0 && conveyer[i])
        {
            conveyer[i] = false;
            conveyer[i + 1] = true;
            naegu[i + 1]--;
        }
    }
    conveyer[N - 1] = false;
}

void put_robot()
{
    if (!conveyer[0] && naegu[0] > 0)
    {
        conveyer[0] = true;
        naegu[0]--;
    }
}

int check()
{
    int cnt = 0;
    for (int i = 0; i < 2 * N; i++)
    {
        if (naegu[i] == 0) cnt++;
    }
    return cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;
    for (int i = 0; i < 2 * N; i++)
    {
        int in;
        cin >> in;
        naegu.push_back(in);
        conveyer.push_back(false);
    }

    step = 1;
    while (true)
    {
        rotate();
        move();
        put_robot();
        if (check() >= K)
        {
            cout << step << "\n";
            break;
        }
        step++;
    }
    return 0;
}

