#include <bits/stdc++.h>

using namespace std;

int n;
vector<long long> a;
unordered_set<long long> s;
unordered_map<long long, long long> next_map;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        s.insert(a[i]);
    }

    // next_map 만들기
    for (long long x : a)
    {
        if (x % 3 == 0 && s.count(x / 3)) 
        {
            next_map[x] = x / 3;
        } 
        else if (s.count(x * 2))
        {
            next_map[x] = x * 2;
        }
    }

    // 시작점 찾기 (역방향이 없는 노드)
    unordered_set<long long> next_values;
    for (auto& [from, to] : next_map)
    {
        next_values.insert(to);
    }
    
    long long start = -1;
    for (long long x : a) 
    {
        if (!next_values.count(x)) 
        {
            start = x;
            break;
        }
    }

    // 수열 복원
    vector<long long> result;
    while (result.size() < n) 
    {
        result.push_back(start);
        if (next_map.count(start)) start = next_map[start];
        else break;
    }

    for (long long x : result)
        cout << x << ' ';
    cout << '\n';

    return 0;
}
