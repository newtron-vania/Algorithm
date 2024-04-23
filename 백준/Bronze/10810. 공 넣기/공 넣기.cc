#include <bits/stdc++.h>

using namespace std;

int main(){
	int arr_n[100] = {0, };
	int n, m;
	cin >> n >> m;

	for(int z=0; z<m; z++){
		int i, j, k;
		cin >> i >> j >> k;
		for(int w = i; w<=j; w++){
			arr_n[w] = k;
		}
	}

	for(int i=1; i<n+1; i++){
		cout << arr_n[i] << " ";
	}
	
	return 0;
}