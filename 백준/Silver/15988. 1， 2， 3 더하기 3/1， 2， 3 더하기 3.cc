#include <vector>
#include <iostream>

using namespace std;

const long long DIVIDE_VALUE =  1'000'000'009;
const int MAX_VALUE = 1'000'000;

int dp[MAX_VALUE+1];
int main()
{
    int cnt;
    cin >> cnt;
    
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    
    for(int i = 4; i <= MAX_VALUE; i++)
    {
        dp[i] = (1LL * dp[i-1] + dp[i-2] + dp[i-3]) % DIVIDE_VALUE;
    }
    
    for(int i = 0; i < cnt; i++)
    {
        int input;
        cin >> input;
        cout << dp[input] << endl;
    }
    
    return 0;
}