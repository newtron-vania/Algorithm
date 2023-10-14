#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{
    int answer = nums.size()/2;
    set<int> nums_set;
    for(int num : nums){
        nums_set.insert(num);
    }
    int num_size = nums_set.size();
    answer = num_size > answer ? answer : num_size;
    return answer;
}