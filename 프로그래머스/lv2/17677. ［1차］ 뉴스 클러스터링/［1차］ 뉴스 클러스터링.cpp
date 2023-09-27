#include <string>
#include <map>
#include <cctype>

using namespace std;

const int MAX = 65536;

string ToLowerStr(string str){
    string tmp = "";
    for(char c : str){
        tmp += tolower(c);
    }
    return tmp;
}

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
            jakard[str.substr(i, count)] += 1;
        }
    }
}

int GetJakardSimilarity(map<string, int>& jakard1, map<string, int>& jakard2){
    map<string, int> jakardMap = jakard1;
    float jakardInter = 0;
    float jakardUnion = 0;
    
    for(auto& itr : jakard2){
        jakardInter += min(jakardMap[itr.first], itr.second);
        jakardMap[itr.first] = max(jakardMap[itr.first], itr.second);
    }
    
    for(auto& itr : jakardMap){
        jakardUnion += itr.second;
    }
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