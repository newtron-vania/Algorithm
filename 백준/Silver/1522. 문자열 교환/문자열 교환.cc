#include <bits/stdc++.h>

using namespace std;

int main()
{

    string input;
    cin >> input;
    
    int length = input.size();
    
    int a_cnt = count(input.begin(), input.end(), 'a');
    int result = 1001;
    for(int i = 0; i < length; i++)
    {
        int sum = 0;
        for(int j = 0; j < a_cnt; j++)
        {
            int idx = (i + j) < length ? i + j : (i + j) - length;
            if(input[idx] != 'a')
            {
                sum++;
            }
        }
        if(sum < result) result = sum;
    }
    
    cout << result << endl;
    return 0;
}