#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    map<string, int> wordDict;
    string lastWord = words[0];
    wordDict.insert(make_pair(words[0], 1));
    int cnt = 1;
    for(int i = 1; i < words.size(); i++){
        if(lastWord.back() != words[i].front()){
            break;
        }
        else if(wordDict.find(words[i]) != wordDict.end()){
            break;
        }
        else{
            wordDict.insert(make_pair(words[i], 1));
            lastWord = words[i];
        }
        cnt++;
    }
    cout << cnt;
    if(cnt < words.size()){
        return {cnt%n+1, cnt/n +1};
    }
    else{
        return {0, 0};
    }
    
}