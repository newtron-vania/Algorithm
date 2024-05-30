#include <bits/stdc++.h>

using namespace std;

int main() 
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int TC, l, n, a, b;
    
  cin >> TC;
    
  while (TC--) 
  {
    int fast = 0, late = 0;
    cin >> l >> n;
    while (n--) 
    {
      cin >> a;
      b = l - a;
      if (a > b) swap(a, b);
      fast = max(fast, a);
      late = max(late, b);
    }
    cout << fast << " " << late << '\n';
  }
}
