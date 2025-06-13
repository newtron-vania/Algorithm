#include <bits/stdc++.h>

using namespace std;
const int MAX_VALUE = 2000000;

int visited[MAX_VALUE];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<int> num;
    
    for(int i = 0; i < n; i++)
    {
        int s;
        cin >> s;
        num.push_back(s);
    }
    
    for(int i = 0; i < (1 << n); i++)
    {
        int sum = 0;
        for(int j = 0; j < n; j++)
        {
            sum += i & (1 << j) ? num[j] : 0;
        }
        visited[sum] = true;
    }
    
    for(int i = 1; i < MAX_VALUE; i++)
    {
        if(!visited[i])
        {
            cout << i;
            break;
        }
    }
}