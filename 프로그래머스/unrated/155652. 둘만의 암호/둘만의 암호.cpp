#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    //사용자용 알파벳 설정 
    map<char, int> alpha_idx;
    map<int, char> idx_alpha;
    int j = 0;
    for(int i = 0; i <26; i++){
        char a = 'a' + i;
        if(skip.find(a) == string::npos){
            idx_alpha[j] = a;
            alpha_idx[a] = j++;
        }
    }
    int len = alpha_idx.size();
    for(char c : s){
        int alpha_key = (alpha_idx[c] + index) % len;
        answer += idx_alpha[alpha_key];
    }

    return answer;
}