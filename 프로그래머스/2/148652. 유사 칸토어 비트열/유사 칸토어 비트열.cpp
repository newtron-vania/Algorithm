#include <string>
#include <vector>
#include <cmath>
using namespace std;

int answer = 0;

void Divide(int n, long long l, long long r)
{
    long long range = 1LL * pow(5,n-1);
    int s = l/range, e = r/range;
    if(n==1)
    {
        for(int i=l;i<=r;i++) if(i!=2) answer++;
        return ;
    }
    for(int i=s+1;i<e;i++) if(i!=2) answer += (int)pow(4,n-1);
    if (s == e) Divide(n-1, l - range*s, r - range*e);
    else
    {
        if(s!=2) Divide(n-1, l - range*s, range-1);
        if(e!=2) Divide(n-1, 0,r - range*e);
    }
}

int solution(int n, long long l, long long r)
{
    Divide(n,--l,--r);
    return answer;
}