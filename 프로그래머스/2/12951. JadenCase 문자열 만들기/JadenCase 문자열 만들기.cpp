#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    // 숫자 확인 및 대문자 처리
    answer += toupper(s[0]);
    for(int i = 1; i < s.length(); i++)
    {
        answer += isspace(s[i-1]) ? toupper(s[i]) : tolower(s[i]);
    }
    
    return answer;
}