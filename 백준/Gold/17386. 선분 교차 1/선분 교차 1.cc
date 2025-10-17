#include <bits/stdc++.h>

using namespace std;

// 세 점의 방향성을 판별하는 CCW 함수
// 반환값 > 0 : 반시계 방향 ↩️
// 반환값 < 0 : 시계 방향 ↪️
// 반환값 = 0 : 일직선 ➖
int ccw(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3)
{
    long long result = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);

    if (result > 0)
    {
        return 1; // 반시계
    }
    else if (result < 0)
    {
        return -1; // 시계
    }
    else
    {
        return 0; // 일직선
    }
}

int main()
{
    long long x1, y1, x2, y2; // 선분 L1의 양 끝점
    long long x3, y3, x4, y4; // 선분 L2의 양 끝점

    scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);
    scanf("%lld %lld %lld %lld", &x3, &y3, &x4, &y4);

    // L1을 기준으로 p3, p4의 방향성 판별
    int ccw123 = ccw(x1, y1, x2, y2, x3, y3);
    int ccw124 = ccw(x1, y1, x2, y2, x4, y4);

    // L2를 기준으로 p1, p2의 방향성 판별
    int ccw341 = ccw(x3, y3, x4, y4, x1, y1);
    int ccw342 = ccw(x3, y3, x4, y4, x2, y2);

    // 두 선분이 교차하는 조건 확인
    bool is_intersect = (ccw123 * ccw124 < 0) && (ccw341 * ccw342 < 0);

    if (is_intersect)
    {
        printf("1\n");
    }
    else
    {
        printf("0\n");
    }

    return 0;
}