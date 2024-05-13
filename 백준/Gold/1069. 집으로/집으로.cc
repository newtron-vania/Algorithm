#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

double X, Y, D, T, ans;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> X >> Y >> D >> T;

	double d = sqrt(pow(X, 2) + pow(Y, 2));
	cout << fixed;
	cout.precision(9);

	if (D < T)
	{
		cout << d << '\n';
	}
	else
	{
		ans = d;

		int jump = d / D; 
		d -= jump * D; 

		if (jump == 0) ans = min(ans, min(T + D - d, 2.0 * T));
		else ans = min(ans, min(jump * T + d, (jump + 1.0) * T));
		
		cout << ans << '\n';
	}
	

}