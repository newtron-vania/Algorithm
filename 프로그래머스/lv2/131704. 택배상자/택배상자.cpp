#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    vector<int> stack;
    //order_idx
    int j = 0;
    for(int i = 1; i <= order.size(); i++){
        stack.push_back(i);
        while(j < order.size() && stack.back() == order[j]){
            stack.pop_back();
            j++;
        }
    }
    answer = j;
    return answer;
}