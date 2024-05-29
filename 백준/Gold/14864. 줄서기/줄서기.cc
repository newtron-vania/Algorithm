#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int n, m;

void check()
{
	vector<int> visit(n+1);
	for(int i=1; i<=n; i++)
    {
		if(v[i] > n || v[i] <= 0)
        {
			cout << -1; exit(0);
		}
		if(visit[v[i]])
        {
			cout << -1; exit(0);
		}
		visit[v[i]] = 1;
	}
}

int main()
{
	ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
	cin >> n >> m;
	v.resize(n+1);
    
	for(int i=1; i<=n; i++) v[i] = i;
	while(m--)
    {
		int a, b; cin >> a >> b;
		v[a]++; v[b]--;
	}

	check();
	for(int i=1; i<=n; i++) 
    {
        cout << v[i] << " ";
    }
    
    return 0;
}