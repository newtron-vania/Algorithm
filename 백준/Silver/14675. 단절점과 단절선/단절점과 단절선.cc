#include <bits/stdc++.h>

using namespace std;

vector<vector<int>>arr; 
int main() 
{
	ios::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
	int n; 
    cin >> n;
	arr.resize(n + 1);
	for (int i = 0; i < n - 1; i++)
    {
		int a, b; cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	int q; cin >> q;
	for (int i = 0; i < q; i++) 
    {
		int a, b; cin >> a >> b;
		if (a == 1)
        {
			if (arr[b].size() > 1)
				cout << "yes\n";
			else
				cout << "no\n";
		}
		else 
        {
			cout << "yes\n";
		}
	}
	return 0;
}