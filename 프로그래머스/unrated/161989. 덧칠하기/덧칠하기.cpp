#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 1;
    int start_section = section[0];
    for(auto& sector : section){
        if(sector - start_section < m){
            continue;
        }
        else{
            start_section = sector;
            answer++;
        }
    }
    return answer;
}