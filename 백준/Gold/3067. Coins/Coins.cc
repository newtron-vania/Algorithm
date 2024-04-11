#include<iostream>
#include<algorithm>
using namespace std;

const int TYPECOUNT = 20;
const int MAX_VALUE = 10000;
int counts[TYPECOUNT];
int dp[TYPECOUNT + 1][MAX_VALUE + 1];

int main()
{
    int T, N, target;
    
    cin >> T;
    
    while(T--)
    {
        cin >> N;
        
        for(int i = 0; i < N; i++)
        {
            cin >> counts[i];
        }
        
        cin >> target;
        
        fill_n(&dp[0][0], (TYPECOUNT + 1) * (MAX_VALUE + 1), 0);
        
        for(int i = 1; i <= N; i++)
        {
            int coinValue = counts[i-1];
            dp[i][coinValue] = 1;
            for(int j = 1; j <= target; j++)
            {
                if(j >= coinValue)
                {
                    dp[i][j] += dp[i][j - coinValue];
                }
                dp[i][j] += dp[i-1][j];
            }
        }
        
        cout << dp[N][target] << endl;
    }
}
