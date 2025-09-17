#include <bits/stdc++.h>

using namespace std;

bool doubles[1000001];

int main()
{
    long long min_v, max_v;
    
    scanf("%lld %lld", &min_v, &max_v);
    
    int cnt = max_v - min_v + 1;
    
    for(long long k = 2; k * k <= max_v; k++)
    {
        long long kk = k * k;
        long long ret = min_v / kk;
		if (min_v % kk != 0)
        {
            ret++;
        }
        
		while (ret * kk <= max_v)
		{	
			if (doubles[ret * kk - min_v] == false)
            {
				doubles[ret * kk - min_v] = true;
				cnt--;
			}
			ret++;
		}
    }
    
    printf("%d", cnt);
}