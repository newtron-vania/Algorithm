#include <bits/stdc++.h>


using namespace std;

int main()
{
    int N, L;
    vector<vector<int>> vec;
    cin >> N >> L;
    
    int start, end;
    
    while(N--)
    {
        cin >> start >> end;
        vec.push_back({start, end});
    }
    sort(vec.begin(), vec.end());
    
    start = 0;
    int answer = 0;
    for(auto v :vec)
    {
        start = v[0] < start ? start : v[0];
        end = v[1] - 1;
        
        if(start > end) continue;
        int count = (end - start + 1) / L + ((end - start + 1) % L ? 1 : 0);
        answer += count;
         
        start = start + L * count;
    }
    cout << answer << endl;
    
    return 0;
}