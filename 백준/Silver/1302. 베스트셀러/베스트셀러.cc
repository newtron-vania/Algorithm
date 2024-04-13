#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    
    map<string, int> book_map;
    
    while(N--)
    {
        string name;
        cin >> name;
        book_map[name]++;
    }
    
    string answer;
    int a_max = 0;
    for(const auto& kv : book_map)
    {
        if(kv.second > a_max)
        {
            answer = kv.first;
            a_max = kv.second;
        }
    }
    cout << answer << endl;
    return 0;
}