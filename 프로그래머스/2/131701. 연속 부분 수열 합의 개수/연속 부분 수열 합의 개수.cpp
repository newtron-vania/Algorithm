#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

unordered_set<int> nums;

int solution(vector<int> elements) {
    int answer = 0;
    vector<int> circle_elements = elements;
    circle_elements.insert(circle_elements.end(), elements.begin(), elements.end());
    
    for(int i = 0; i < circle_elements.size() / 2; i++)
    {
        int sum = 0;
        for(int j = 0; j < circle_elements.size() / 2; j++)
        {
            sum += circle_elements[i + j];
            nums.insert(sum);
        }
    }
    
    answer = nums.size();
    return answer;
}