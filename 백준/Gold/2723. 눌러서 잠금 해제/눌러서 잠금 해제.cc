#include <bits/stdc++.h>

using namespace std;

const int MAX_VALUE = 1 << 11;
int combine[MAX_VALUE] = {0, };

int main()
{
    int n;
    cin >> n;
    
    for(int i = 1; i < MAX_VALUE; i++)
    {
        int sum = 0;
        for(int j = 1; j < i; j++)
        {
            if ((i & j) == j)
            {
                sum += combine[j];
            }
        }
        sum += 1;
        combine[i] = sum;
    }
    
    while(n-- > 0)
    {
        int input;
        cin >> input;
        
        int value = combine[(1 << input) - 1];
        
        long long output = 1LL * value * 2 - 1;
        
        cout << output << endl;
    }
    
}