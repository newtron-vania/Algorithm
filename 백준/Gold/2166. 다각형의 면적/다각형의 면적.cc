#include <bits/stdc++.h>

using namespace std;

const int MAX = 1001;
int N;
vector<pair<int, int>> vec;

double external(double x1, double x2, double x3, double y1, double y2, double y3)
{
    double temp = (x1*y2 + x2*y3 + x3*y1) - (x2*y1 + x3*y2 + x1*y3);
    return temp / 2;
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    int x, y;
    for(int i = 0; i < N; i++) 
    {
        cin >> x >> y;
        vec.push_back({x, y});
    }

    double res = 0;
    for(int i = 1; i < N; i++)
    {
        res += external(vec[0].first, vec[i-1].first, vec[i].first, 
                        vec[0].second, vec[i-1].second, vec[i].second);
    }

    cout.precision(1);
    cout << fixed;
    cout << abs(res);

    return 0;
}