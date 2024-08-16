#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<long long> solution(vector<long long> numbers)
{
    vector<long long> answer;
    for(long long number : numbers)
    {
        long long num = 1;
        while((number & num) > 0) num <<= 1;
        answer.push_back(number + num - (num >>1));
    }
    return answer;
}