#include <iostream>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    char c[5][15] = { 0 };


    for (int i = 0; i < 5; i++) 
    {
        cin >> c[i];
    }
    for (int i = 0; i < 15; i++) 
    {
        for (int j = 0; j < 5; j++) 
        {
            if (c[j][i] == 0)continue;
            cout << c[j][i];
        }
    }
}