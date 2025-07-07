#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

bool is_better(const vector<int>& a, const vector<int>& b) {
    for (int i = 10; i >= 0; --i) {
        if (a[i] > b[i]) return true;
        else if (a[i] < b[i]) return false;
    }
    return false; // 같음
}

vector<int> solution(int n, vector<int> info) {
    int maxScoreDiff = 0;
    int maxBit = 1;
    vector<int> maxArray(11);
    for(int bit = 1; bit != (1 << 11); bit++){
        int count = 0;
        int score = 0;
        int targetScore = 0;
        
        vector<int> array(11);
        
        for(int i = 0; i < 10; i++){
            if(bit&(1<<i)){
                array[i] += info[i] + 1;
                count += info[i] + 1;
                score += 10 - i;
            }
            else{
                if(info[i] != 0)
                    targetScore += 10 - i;
            }
        }
        if(count <= n){
            if(count < n){
                array[10] += n - count;
            }
            if(targetScore < score){
                int scoreDiff = score - targetScore;
                if(maxScoreDiff < scoreDiff){
                    maxScoreDiff = scoreDiff;
                    maxBit = bit;
                    maxArray = array;
                }
                else if(maxScoreDiff == scoreDiff){
                    if (is_better(array, maxArray)){
                        maxBit = bit;
                        maxArray = array;
                    }
                }
            }
        }
    }
    if(maxScoreDiff <= 0){
        vector<int> answer = {-1};
        return answer;
    }
    return maxArray;
}
