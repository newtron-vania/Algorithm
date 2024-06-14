#include <bits/stdc++.h>

using namespace std;

int main() 
{
	ios::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    
    int T;
    cin >> T;
    
    while(T--)
    {
        int answer = 0;
        string a, b;
        cin >> a >> b;
        
        int a_pos = 0, b_pos = 0;
        for(int i = 0; i < a.length(); i++)
        {
            if(a[i] == 'a')
            {
                while(b[b_pos] != 'a') b_pos++;
                answer += abs(i - b_pos);
                b_pos++;
            }
        }
        
        cout << answer << endl;
    }
	return 0;
}