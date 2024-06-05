#include <bits/stdc++.h>

using namespace std;

int main()
{
    string ss;
    
    while(true)
    {
        getline(cin, ss);
        if(!ss.compare("END"))
        {
            break;
        }
        
        reverse(ss.begin(), ss.end());
        cout << ss << endl;
    }
}