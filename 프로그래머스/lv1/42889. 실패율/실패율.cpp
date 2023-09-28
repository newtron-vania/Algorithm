#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(pair<int, double>& a, pair<int, double>& b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> lived(N + 1, 0);
    for (int stage : stages) {
        lived[stage - 1]++;
    }
    
    vector<int> success(N + 1, 0);
    success[N] = lived[N];
    for (int i = N; i > 0; i--) {
        success[i - 1] = success[i] + lived[i - 1];
    }
    
    vector<pair<int, double>> failed;
    for (int i = 0; i < N; i++) {
        if (success[i] == 0) {
            failed.push_back({i + 1, 0.0});
        } else {
            failed.push_back({i + 1, static_cast<double>(lived[i]) / success[i]});
        }
    }
    
    sort(failed.begin(), failed.end(), compare);
    
    vector<int> answer;
    for (pair<int, double>& p : failed) {
        answer.push_back(p.first);
    }
    
    return answer;
}