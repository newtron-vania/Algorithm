#include<bits/stdc++.h>

using namespace std;

const int MAX = 100000;
int arr[MAX], seg[4*MAX];

inline int minIdx(int a, int b)
{
	if(a==-1) return b;
	if(b==-1) return a;
	return arr[a] <= arr[b] ? a : b;
}
    
int init(int l, int r, int node)
{
	if(l == r) return seg[node] = l;
	int mid = (l+r)/2;
	return seg[node] = minIdx(init(l, mid, node*2), init(mid+1, r, node*2+1));
}
    
int query(int l, int r, int node, int nodeL, int nodeR)
{
	if(r < nodeL || nodeR < l) return -1; //구간이 겹치지 않으면 무시.
	if(l <= nodeL && nodeR <=r) return seg[node]; //구간이 완전히 겹침.
	int mid = (nodeL + nodeR)/2;
	return minIdx(query(l, r, node*2, nodeL, mid), query(l, r, node*2+1, mid+1, nodeR));
}
    
int update(int index, int value, int node, int nodeL, int nodeR)
{
	if(index<nodeL || nodeR<index || nodeL == nodeR) return seg[node];
	int mid = (nodeL + nodeR)/2;
	return seg[node] = minIdx(update(index,value,node*2,nodeL,mid),update(index,value,node*2+1,mid+1,nodeR));
}
    
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin >> n;
	for(int i=0; i<n; i++)
		cin >> arr[i];
	init(0, n-1, 1);
	cin >> m;
	while(m--)
    {
		int a,b,c;
		cin >> a;
		if(a==1)
        {
			cin >> b >> c;
			arr[b-1] = c;
			update(b-1, c, 1, 0, n-1);
		}
		else cout << query(0, n-1, 1, 0, n-1)+1 << '\n';
	}
}