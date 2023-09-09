#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> time;
    int len = progresses.size();
    for(int i = 0 ; i<len; i++){
        time.push_back(ceil((100 -progresses[i]) / (float)speeds[i]));
    }
    int start = 0;
    int end = 0;
    while(end < len){
        if(time[start] >= time[end]){
            end++;
        }
        else{
            answer.push_back(end - start);
            start = end;
        }
    }
    answer.push_back(end - start);
    return answer;
}