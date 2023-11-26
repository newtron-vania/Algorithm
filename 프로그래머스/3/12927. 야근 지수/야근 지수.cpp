#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    int work_size = works.size();
    
    priority_queue<int> pq;
    for(int work : works) { pq.push(work);}
    while(n-- > 0 && pq.top() != 0)
    {
        int work = pq.top();
        pq.pop();
        work--;
        pq.push(work);
    }
    while(!pq.empty())
    {
        answer += 1LL * pq.top() * pq.top();
        pq.pop();
    }
    
    return answer;
}