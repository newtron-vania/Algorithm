#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int array[101];
 
    for (int i = 1; i < n + 1; i++) {
        array[i] = i;
    }
 
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        swap(array[a], array[b]);
    }
 
    for (int i = 1; i < n + 1; i++) {
        cout << array[i] << " ";
    }
         
    return 0;
}