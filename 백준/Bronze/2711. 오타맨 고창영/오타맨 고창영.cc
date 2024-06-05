#include <iostream>
#include <string>

using namespace std;

int main() 
{
    int T,index;
    string w;
    cin >> T;
    
    for (int i = 0; i < T; i++)
    {
        cin >> index >> w;
        for (int i = 0; i < w.size(); i++)
        {
            if (i != index - 1)
                cout << w[i];
        }
        cout << '\n';
    }
}