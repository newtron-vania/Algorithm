#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

struct comp{
    bool operator()(vector<int> a, vector<int> b){
    return a[1] > b[1];
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    priority_queue<vector<int>, vector<vector<int>>, comp> pq;
    sort(jobs.begin(), jobs.end());
    int idx = 0;
    int end_time = 0;
    vector<int> job;
    while(idx < jobs.size() || !pq.empty()){
        while(idx < jobs.size() && end_time >= jobs[idx][0]){
            pq.push(jobs[idx++]);
        }
        if(!pq.empty()){
            vector<int> vec = pq.top();
            pq.pop();
            end_time += vec[1];
            answer += end_time - vec[0];
        }
        else{
            end_time = jobs[idx][0];
        }
    }
    return answer / jobs.size();
}