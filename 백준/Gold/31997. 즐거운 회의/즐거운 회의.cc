#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M, T;
    scanf("%d %d %d", &N, &M, &T);
    
    vector<pair<int, int>> attendance(N);
    for (int i = 0; i < N; ++i) 
    {
        scanf("%d %d", &attendance[i].first, &attendance[i].second);
    }
    
    unordered_map<int, vector<int>> friendships;
    for (int i = 0; i < M; ++i) 
    {
        int a, b;
        scanf("%d %d", &a, &b);
        if (a > b) swap(a, b);
        friendships[a - 1].push_back(b - 1);
    }

    vector<int> active(T + 1, 0);

    for (int i = 0; i < N; ++i) 
    {
        int a_start = attendance[i].first;
        int a_end = attendance[i].second;
        for (int j : friendships[i]) 
        {
            int b_start = attendance[j].first;
            int b_end = attendance[j].second;
            int start = max(a_start, b_start);
            int end = min(a_end, b_end);
            if (start < end) 
            {
                active[start]++;
                active[end]--;
            }
        }
    }


    int current_active = 0;
    for (int t = 0; t < T; ++t) 
    {
        current_active += active[t];
        printf("%d\n", current_active);
    }
    
    return 0;
}
