#include <bits/stdc++.h>

using namespace std;

int main()
{
    string c;
    cin >> c;
    string d = c;
    reverse(d.begin(), d.end());
    
    cout << (!d.compare(c)) << endl;
}