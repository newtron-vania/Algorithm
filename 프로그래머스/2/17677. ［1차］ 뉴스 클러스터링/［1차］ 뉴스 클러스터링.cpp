#include <string>
#include <map>
#include <cctype>

using namespace std;

//상수
const int MAX = 65536;

//소문자로 변경
string ToLowerStr(string str){
    string tmp = "";
    for(char c : str){
        tmp += tolower(c);
    }
    return tmp;
}

//다중 집합 생성
//count(=2) 만큼 글자를 끊어 영문자로만 이루어진 글자를 저장한다.
void MakeJakard(map<string, int>& jakard, string str, int count){
    for(int i = 0; i < str.length()-count+1; i++){
        string tmp = str.substr(i, count);
        bool isAp = true;
        for(int i = 0; i < count; i++){
            if(!isalpha(tmp[i])){
                isAp = false;
                break;
            }
        }
        if(isAp){
            jakard[tmp] += 1;
        }
    }
}

//자카드 유사도 함수
//두 집합의 교집합과 합집합을 구하여 자카드 유사도를 반환
int GetJakardSimilarity(map<string, int>& jakard1, map<string, int>& jakard2){
    map<string, int> jakardMap = jakard1;
    float jakardInter = 0;
    float jakardUnion = 0;
    
    for(auto& itr : jakard2){
        jakardInter += min(jakardMap[itr.first], itr.second);   //  교집합 개수
        jakardMap[itr.first] = max(jakardMap[itr.first], itr.second);   //합집합 개수
    }
    
    for(auto& itr : jakardMap){
        jakardUnion += itr.second;
    }
    //if(합집합.size() == 0) 공집합 -> MAX 반환 
    return jakardUnion > 0 ? jakardInter / jakardUnion * MAX : MAX;
}
int solution(string str1, string str2) {
    int answer = 0;
    str1 = ToLowerStr(str1);
    str2 = ToLowerStr(str2);
    
    map<string, int> str1Jakard;
    map<string, int> str2Jakard;
    
    MakeJakard(str1Jakard, str1, 2);
    MakeJakard(str2Jakard, str2, 2);
    
    answer = GetJakardSimilarity(str1Jakard, str2Jakard);
    return answer;
}