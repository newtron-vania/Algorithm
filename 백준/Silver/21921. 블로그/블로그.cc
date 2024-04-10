#include <bits/stdc++.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, X;
    cin >> N >> X;
    
    vector<int> graph(N, 0);
    for(int i = 0; i < N; i++) {
        int x;
        cin >> x;
        graph[i] = x;
    }
    
    int maxSum = 0;
    int count = 0;
    int sum = 0;
    for(int i = 0; i < N; i++) {
        sum += graph[i];
        if(i >= X) {
            sum -= graph[i - X];
        }
        if(maxSum <= sum)
        {
            if(maxSum == sum)
            {
                count++;
            }
            else
            {
                maxSum = sum;
                count = 1;
            }
        }
    }
    
    if(maxSum > 0)
    {
        cout << maxSum << endl;
        cout << count << endl;
    }
    else
    {
        cout << "SAD" << endl;
    }
    return 0;
}