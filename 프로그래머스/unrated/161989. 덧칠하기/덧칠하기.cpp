#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 1;
    if(section.size() <= 1)
        return answer;
    
    
    int start_section = section[0];
    for(int i = 1; i < section.size(); i++){
        if(section[i] - start_section < m){
            continue;
        }
        else{
            start_section = section[i];
            answer++;
        }
    }
    return answer;
}