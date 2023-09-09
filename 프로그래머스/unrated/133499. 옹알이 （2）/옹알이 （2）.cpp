#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    vector<string> words{"aya", "ye", "woo", "ma"};
    
    for(string babble : babbling){
        int idx = 0;
        int current_idx = 0;
        string current_word;
        while(idx < babble.length()){
            for(string word : words){
                if(current_word != word && babble.substr(idx, word.length()) == word){
                    current_idx += word.length();
                    current_word = word;
                    break;
                }
            }
            if(idx == current_idx)
                break;
            idx = current_idx;
        }
        if(idx == babble.length())
            answer++;
    }
    return answer;
}