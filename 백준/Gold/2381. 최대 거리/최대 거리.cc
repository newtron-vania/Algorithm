#include <bits/stdc++.h>

using namespace std;
 

 
int main() 
{
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
    
    int n, a, b;
    vector<int> p, m;
 
	cin >> n;
	for (int i = 0; i < n; i++) 
    {
		cin >> a >> b;
		p.push_back(a + b);
		m.push_back(a - b);
	}
    
	sort(p.begin(), p.end()), sort(m.begin(), m.end());
	cout << max(p[n - 1] - p[0], m[n - 1] - m[0]);
}