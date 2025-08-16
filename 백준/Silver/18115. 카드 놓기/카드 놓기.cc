#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    
    scanf("%d", &n);
    
    vector<int> cmd;
    
    for(int i = 0; i < n; i++)
    {
        int v;
        scanf("%d", &v);
        cmd.push_back(v);
    }
    
    vector<int> vec(n);
    deque<int> dq(n);
    
    iota(dq.begin(), dq.end(), 0);
    
    for(int i = 0 ; i < n; i++)
    {
        int t;
        if(cmd[i] == 1)
        {
            t = dq.front();
            dq.pop_front();
        }
        else if(cmd[i] == 3)
        {
            t = dq.back();
            dq.pop_back();
        }
        else
        {
            t = dq[1];
            dq.erase(dq.begin() + 1);
        }
        vec[t] = n - i;
    }
    
    for(int i = 0; i < n; i++)
    {
        printf("%d ", vec[i]);
    }
    
}