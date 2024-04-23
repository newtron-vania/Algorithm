#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int t;
    string str;
    cin >> t;
    
    for(int i = 0; i < t; i++) 
    {
        cin >> str;
        int size = str.length();
        cout << str[0] << str[size-1] << "\n";
    }
    
    return 0;
}