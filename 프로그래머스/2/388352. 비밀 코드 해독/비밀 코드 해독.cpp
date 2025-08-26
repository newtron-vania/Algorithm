#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int n, vector<vector<int>> q, vector<int> ans)
{
    int m = q.size();
    int answer = 0;
    vector<int> comb(n);
    for (int i = 0; i < 5; ++i)
    {
        comb[n - i - 1] = 1;
    }

    do 
    {
        bool f = true;
        for (int i = 0; i < m; ++i) 
        {
            if (ans[i] != comb[q[i][0] - 1] + comb[q[i][1] - 1] + comb[q[i][2] - 1] + comb[q[i][3] - 1] + comb[q[i][4] - 1]) 
            {
                f = false;
                break;
            }
        }
        if (f) ++answer;
    } while(next_permutation(comb.begin(), comb.end()));
    return answer;
}
