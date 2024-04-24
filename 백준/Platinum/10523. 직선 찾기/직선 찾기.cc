#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

// 난수 설정
random_device rd;
mt19937 generator(rd());

ll ccw(pll a, pll b, pll c)
{
    return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

int randint(int l, int r)
{
    return uniform_int_distribution<int> (l, r)(generator);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // 점의 개수가 2개 이하라면 무조건 가능하다.
    int n; cin >> n;
    if (n <= 2)
    {
        cout << "possible";
        return 0;
    }

    // 지나야 하는 점의 개수가 2개 이하라면 무조건 가능하다.
    int p; cin >> p;
    int m = ceil(n * p * 0.01);
    if (m <= 2)
    {
        cout << "possible";
        return 0;
    }

    pll points[n];
    for (int i = 0; i < n; i++) cin >> points[i].x >> points[i].y;

    time_t st = time(0); // 시작 시간 체크
    while (true)
    {
        // 직선의 양 끝점이 될 두 점을 무작위로 뽑는다.
        vector<pll> ends;
        while (ends.size() < 2)
        {
            pll p = points[randint(0, n - 1)];
            if (find(ends.begin(), ends.end(), p) == ends.end())
            {
                ends.push_back(p);
            }
        }

        // 양 끝점과 ccw가 0인 점의 개수를 구한다.
        int result = 0;
        for (int i = 0; i < n; i++) 
        {
            if (!ccw(ends[0], ends[1], points[i]))
                if (++result == m) break;
        }

        // 지나야 하는 점의 개수를 도달했다면 성공
        if (result == m)
        {
            cout << "possible";
            break;
        }

        // 시작 시간으로부터 3초가 지났다면 불가능한 것으로 간주하고 종료
        if (time(0) - st > 3)
        {
            cout << "impossible";
            break;
        }
    }
}