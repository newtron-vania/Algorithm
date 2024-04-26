#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m;
    vector<int> answer;
    
    cin >> n;
    int* bq = new int[n];
    for(int i = 0; i < n; i++)
    {
        cin >> bq[i];
    }
    
    for(int i = 0 ; i < n; i++)
    {
        int a;
        cin >> a;
        if(!bq[i])
        {
            answer.push_back(a);
        }
    }
    
    delete[] bq;
    
    reverse(answer.begin(), answer.end());
    
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        int b;
        cin >> b;
        answer.push_back(b);
    }
    
    for(int i = 0; i < m; i++)
    {
        cout << answer[i] << " ";
    }
    
    return 0;
}