#include <cstdio>
#include <algorithm>

using namespace std;
 
int k, q;
long long int n;
 
long long int get_depth(long long int val)
{
	
	long long int depth = 0;
 
	if (k == 1) {
		depth = val;
	}
	else
	{
		if (val != 0)
		{
			depth = 1;
			long long int left = 1, right = k;
 
			while (!(left <= val && val <= right)) 
            {
				++depth;
				left = left * k + 1;
				right = right * k + k;
			}
		}
	}
	return depth;
}
 
long long int get_parent(long long int u)
{
	long long int parent;
 
	parent = (u - 1) / k;
 
	return parent;
}
 
long long int get_distance(long long int u, long long int v) 
{
	long long int depth_u = 0, depth_v = 0;
	long long int ans = 0;
 
	depth_u = get_depth(u);
	depth_v = get_depth(v);
 
	if (depth_u < depth_v) {
		swap(depth_u, depth_v);
		swap(u, v);
	}
	//u is deeper than v
 
	if (k == 1) {
		ans = depth_u - depth_v;
	}
	else
	{
		long long int diff = depth_u - depth_v;
 
		ans += diff;
		for (int i = 0; i < diff; ++i) 
			u = get_parent(u);
		
		while (u != v) {
			u = get_parent(u);
			v = get_parent(v);
			ans += 2;
		}
	}
 
	return ans;
}
 
int main()
{
	scanf("%lld %d %d", &n, &k, &q);
 
 
	for (int i = 0; i < q; ++i)
    {
		long long int u, v;
		scanf("%lld %lld", &u, &v);
 
		printf("%lld\n", get_distance(u - 1, v - 1));
	}
 
 
	return 0;
}