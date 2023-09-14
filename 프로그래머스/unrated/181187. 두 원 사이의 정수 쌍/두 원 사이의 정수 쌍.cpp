#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long cnt_dots(int r)
{//원위의 점을 포함한 모든점
    long long cnt = r;
    for(int i=1;i<r;i++)
        cnt += (long long)sqrt(1LL*r*r - 1LL*i*i);
    return cnt*4+1;
}

long long cnt_inside_dots(int r)
{//원위의 점을 제외한 내부의 점
    long long cnt = r - 1;
    for(int i=1;i<r;i++)
    {
        long long tmp = (long long)sqrt(1LL*r*r - 1LL*i*i);
        if(tmp*tmp + 1LL*i*i == 1LL*r*r) cnt += tmp - 1;
        else cnt += tmp;
    }
    return cnt*4+1;
}

long long solution(int r1, int r2)
{
    return cnt_dots(r2) - cnt_inside_dots(r1);
}