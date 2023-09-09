#include <string>
#include <vector>
#include <iostream>

using namespace std;
bool isFound = false;
void dfs(string tmp, string word, int &result, int &answer){
    vector<char> alpha = {'A', 'E', 'I', 'O', 'U'};
    if(isFound)
        return;
    if(tmp.compare(word) == 0){
        answer = result;
        isFound = true;
        return;
    }
    if(tmp.size() < 5){
        for(int i = 0; i<5; i++){
            result++;
            dfs(tmp + alpha[i], word, result, answer);
        }
    }
    
}

int solution(string word) {
    int answer = 0;
    int result = 0;
    string tmp = "";
    dfs("", word, result, answer);
    
    return answer;
}