#include <string>
#include <vector>
#include <iostream>
 
using namespace std;
 
int emo = 0;
int price = 0;
vector<int> vec;
int arr[4] = {10,20,30,40};
 
void dfs(vector<vector<int>> users, vector<int> emoticons) {                        
    if(vec.size() == emoticons.size()) {
        int emo_tmp = 0;
        int price_tmp = 0;
        
        for(int i=0; i<users.size(); i++) {
            int p = 0;
            
            for(int j=0; j<emoticons.size(); j++) {
                if(users[i][0] <= vec[j]) {
                    p = p + emoticons[j] * (100-vec[j]) / 100;
                }
            }
            
            if(p >= users[i][1]) { emo_tmp++; }
            else { price_tmp = price_tmp + p; }
        }
        
        if(emo < emo_tmp) {
            emo = emo_tmp;
            price = price_tmp;
        }
        else if(emo == emo_tmp && price < price_tmp) {
            price = price_tmp;
        }
        return;
    }
    
    for(int i=0; i<4; i++) {
        vec.push_back(arr[i]);
        dfs(users,emoticons);
        vec.pop_back();
    }
}
 
vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    
    dfs(users,emoticons);
    
    answer.push_back(emo);
    answer.push_back(price);
    
    return answer;
}
