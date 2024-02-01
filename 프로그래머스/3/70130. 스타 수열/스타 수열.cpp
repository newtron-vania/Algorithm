#include <string>
#include <vector>
#include <algorithm>
using namespace std;
 
int Max(int A, int B) 
{ 
    return A > B ? A : B; 
}
bool Cmp(int A, int B) 
{ 
    return A > B ? true : false; 
}
 
int solution(vector<int> a)
{
    int answer = -1;
    vector<int> cnt_vec(a.size() + 1, 0);
    
    for (int i = 0; i < a.size(); i++) 
    {
        cnt_vec[a[i]]++;
    }
 
    for (int i = 0; i < cnt_vec.size(); i++)
    {
        if (cnt_vec[i] == 0) continue;
        if (cnt_vec[i] <= answer) continue;
        
        int Result = 0;
        
        for (int j = 0; j < a.size() - 1; j++)
        {
            if (a[j] != i && a[j + 1] != i) continue;
            if (a[j] == a[j + 1]) continue;
            
            Result++;
            j++;
        }
        answer = Max(answer, Result);
    }
    return answer * 2;
}
 
