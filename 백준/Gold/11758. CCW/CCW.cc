#include <bits/stdc++.h>

using namespace std;

struct Point 
{
    long long x, y;
};

long long ccw(Point a, Point b, Point c) 
{
    long long cross = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    if (cross > 0) return 1;      // 반시계 방향
    else if (cross < 0) return -1; // 시계 방향
    else return 0;                // 일직선
}

int main() 
{
    Point a, b, c;
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;

    cout << ccw(a, b, c) << "\n";

    return 0;
}