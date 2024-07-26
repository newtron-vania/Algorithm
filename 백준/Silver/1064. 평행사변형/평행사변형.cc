#include <bits/stdc++.h>
using namespace std;

double solve(double xa, double ya, double xb, double yb, double xc, double yc) 
{
    if ((xa - xb) * (ya - yc) == (ya - yb) * (xa - xc)) {
        return -1.0;
    }

    double ab = sqrt((xa - xb) * (xa - xb) + (ya - yb) * (ya - yb));
    double ac = sqrt((xa - xc) * (xa - xc) + (ya - yc) * (ya - yc));
    double bc = sqrt((xb - xc) * (xb - xc) + (yb - yc) * (yb - yc));

    vector<double> l = {ab + ac, ab + bc, ac + bc};

    double result = *max_element(l.begin(), l.end()) - *min_element(l.begin(), l.end());
    return 2 * result;
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    double xa, ya, xb, yb, xc, yc;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;

    double answer = solve(xa, ya, xb, yb, xc, yc);
    cout << fixed << setprecision(16) << answer << '\n';

    return 0;
}
