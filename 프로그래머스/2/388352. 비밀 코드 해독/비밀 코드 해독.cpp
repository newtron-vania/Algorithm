#include <string>
#include <vector>
 
using namespace std;
 
int answer;
 
void check(int pwd, vector<vector<int>> q, vector<int> ans)
{
    for(int i = 0; i < q.size(); i++)
    {
        int compare = 0, cnt = 0;
        for(int bit : q[i]) compare += (1 << bit-1);
        cnt = __builtin_popcount(pwd & compare);
        if(cnt != ans[i]) return;
    }
    answer++;
}
 
int solution(int n, vector<vector<int>> q, vector<int> ans) 
{
    int pwd = 0;
    
    for(int i=1; i<=n-4; i++)
    {
        for(int j=i+1; j<=n-3; j++)
        {
            for(int k=j+1; k<=n-2; k++)
            {
                for(int l=k+1; l<=n-1; l++)
                {
                    for(int m=l+1; m<=n; m++)
                    {
                        pwd = (1 << (i-1)) | (1 << (j-1)) | (1 << (k-1)) | (1 << (l-1)) | (1 << (m-1));
                        check(pwd, q, ans);
                    }
                }
            }
        }
    }
 
    return answer;
}