#include <iostream>
using namespace std;

int n = 0;

bool checked(int num) {
	for (int i = 2; i*i <= num; i++) {
		if (num%i == 0)
			return false;
	}
	return true;
}

void dfs(int num, int len, int n) {
	if (len == n) {
		cout << num << "\n";
		return;
	}

	for (int i = 1; i <= 9; i++) {
		if (checked(num * 10 + i))
			dfs(num * 10 + i, len + 1, n);
	}

	return;
}

int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
    
    int n;
    cin >> n;
    
    dfs(2, 1, n);
    dfs(3, 1, n);
    dfs(5, 1, n);
    dfs(7, 1, n);
    
    return 0;
}