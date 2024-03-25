#include <string>
#include <vector>
#include <queue>

using namespace std;


int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> queue;
    for(int scovil : scoville){
        queue.push(scovil);
    }
    while(queue.top() < K){
        if(queue.size() < 2)
            return -1;
        int a = queue.top();
        queue.pop();
        int b = queue.top();
        queue.pop();
        int sum = a + b*2;
        answer++;
        queue.push(sum);
    }
    return answer;
}