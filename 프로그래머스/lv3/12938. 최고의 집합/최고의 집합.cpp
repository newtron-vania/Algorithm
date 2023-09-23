#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<vector<int>> multi_set;


vector<int> solution(int n, int s) {
    vector<int> temp;

    if (s < n)
        return {-1};
    
    for (int i = 0; i < n; i++) {
        temp.push_back(s / n);
    }

    int tempSize = s % n;
    int tempInt = 0;
    while (tempSize--) {
        temp[temp.size() - ++tempInt]++;
    }
    
    return temp;
}