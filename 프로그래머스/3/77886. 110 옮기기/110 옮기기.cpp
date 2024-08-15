#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> s) {
    vector<string> answer;
    
    for (auto str: s) {
        string acc = ""; // 문자열의 "110" 개수만큼 "110" 더하기
        string tmp = "";
        
        for (int i=0; i<str.length(); i++) {
            tmp += str[i];
            
            if (tmp.length() >= 3) {
                if (tmp.substr(tmp.length()-3, 3) == "110") {
                    tmp.erase(tmp.length()-3, 3);
                    acc += "110";
                }    
            }
        }
        
        str = tmp;
        
        // 문자열에서 마지막 '0'의 인덱스 찾기
        int lastZeroIdx = -1;
        for (int i=str.length()-1; i>=0; i--) {
            if (str[i] == '0') {
                lastZeroIdx = i;
                break;
            }
        }
        
        // 문자열이 1로만 이루어진 경우
        if (lastZeroIdx == -1) {
            str = acc + str;
        } else {
            str.insert(lastZeroIdx+1, acc);
        }
        
        answer.push_back(str);
    }
    
    return answer;
}