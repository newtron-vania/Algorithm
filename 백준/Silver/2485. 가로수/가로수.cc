#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b)
{
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int main()
{
    int n;
    cin >> n;
    
    vector<int> vec(n, 0);
    
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        vec[i] = a;
    }
    
    vector<int> vec2(n-1, 0);
    for(int i = 1; i < n; i++)
    {
        vec2[i - 1] = vec[i] - vec[i - 1];
    }
    
    int result = gcd(vec2[0], vec2[1]);
    for(int i = 2; i < vec2.size(); i++)
    {
       result = gcd(result, vec2[i]);
    }
    
    int answer = 0;
    for(int v : vec2)
    {
        answer += (v / result) - 1;
    }
    cout << answer << endl;
    
}