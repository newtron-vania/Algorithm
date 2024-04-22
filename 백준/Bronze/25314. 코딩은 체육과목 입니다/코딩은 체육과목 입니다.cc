#include <bits/stdc++.h>


using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    
    int result = n / 4;
    
    for(int i = 0; i < result; i++)
    {
        cout << "long ";
    }
    cout << "int" << endl;
    
    return 0;
}