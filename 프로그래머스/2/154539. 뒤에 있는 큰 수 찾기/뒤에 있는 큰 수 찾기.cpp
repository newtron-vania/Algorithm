#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size(), -1);
    stack<pair<int, int>> stk;
    for(int i = 0; i < numbers.size(); i++)
    {
        while(!stk.empty() && stk.top().second < numbers[i])
        {
            auto pop_value = stk.top();
            answer[pop_value.first] = numbers[i];
            stk.pop();
        }
        stk.push(pair<int, int>(i, numbers[i]));
    }
    return answer;
}