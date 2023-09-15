#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    priority_queue<int, vector<int>> pq;
    
    int sum = 0;
    int i = 0;
    for(; i < enemy.size(); i++){
        pq.push(enemy[i]);
        sum += enemy[i];
        if(sum > n){
            if(k > 0){
                sum -= pq.top();
                pq.pop();
                k -= 1;
            }
            else{
                break;
            }
        }
    }
    answer = i;
    return answer;
}