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
        /* 
        aababb -> aaabbb 언제나, a, b의 개수가 같고, b의 좌측에 있는 b보다 많으면 좋은 문자열
        어떻게 인접한 문자를 변경해도 무조건 좋은 문자열이다.
        */
        
        vector<int> a_idx;
        vector<int> b_idx;
        for(int i = 0; i < a.length(); i++)
        {
            if(a[i] == 'a') a_idx.push_back(i);
            if(b[i] == 'a') b_idx.push_back(i);
        }
        
        for(int i = 0; i < a_idx.size(); i++)
        {
            answer += abs(a_idx[i] - b_idx[i]);
        }
        
        cout << answer << endl;
    }
	return 0;
}