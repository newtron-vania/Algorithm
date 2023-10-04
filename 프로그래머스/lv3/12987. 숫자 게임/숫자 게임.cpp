#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int idx = 0;
    for(int num : A){
        while(idx < B.size()){
            if(B[idx++]  > num) {answer++; break;}
        }
    }
    
    return answer;
}