#include <string>
#include <vector>
#include <iostream>

using namespace std;
long long Sum(vector<int> vec)
{
    long long result = 0;
    for(int v : vec)
    {
        result += v;
    }
    return result;
}


int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    long queue1_sum = Sum(queue1);
    long queue2_sum = Sum(queue2);
    
    long long sum = queue1_sum + queue2_sum;
    
    
    int q_size = queue1.size();
    int idx1 = 0;
    int idx2 = 0;
    while(queue1_sum != queue2_sum && answer <= 4*q_size)
    {
        if(queue1_sum > queue2_sum)
        {
            int element = idx1 < q_size ? queue1[idx1] : queue2[idx1 % q_size];
            queue1_sum -= element;
            queue2_sum += element;
            idx1 += 1;
        }
        else
        {
            int element = idx2 < q_size ? queue2[idx2] : queue1[idx2 % q_size];
            queue1_sum += element;
            queue2_sum -= element;
            idx2 += 1;
        }
        answer += 1;
    }
    return answer <= q_size*4 ? answer : -1;
}