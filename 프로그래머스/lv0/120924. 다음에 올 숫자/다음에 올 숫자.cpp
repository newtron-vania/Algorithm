#include <string>
#include <vector>

using namespace std;

int solution(vector<int> common) {
    int answer = 0;
    bool isPlus = false;
    
    int pa = common[1] - common[0];
    int pb = common[2] - common[1];
    if(pa == pb)
        isPlus = true;
    
    answer = isPlus ? common.back() + pa : common.back()*((float)common[1] / common[0]);
    return answer;
}