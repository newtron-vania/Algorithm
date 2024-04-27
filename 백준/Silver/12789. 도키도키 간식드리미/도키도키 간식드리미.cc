#include <bits/stdc++.h>
using namespace std;

stack<int> S;
int N, T, cnt=1;

int main()
{	
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> N; // 학생들의 수. 
	
	while(N--)
    {
		cin >> T;
		
		if(T==cnt) cnt++;
		else S.push(T); 
		
		while(!S.empty()&&S.top()==cnt)
        {
			S.pop(); 
			cnt++;
		}
	}
	
	if(S.empty()) cout << "Nice"; 
	else cout << "Sad";
}