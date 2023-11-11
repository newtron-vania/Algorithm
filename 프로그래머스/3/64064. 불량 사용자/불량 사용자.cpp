#include <string>
#include <vector>
#include <iostream>
#include <set>



using namespace std;


/**
제재 아이디의 경우의 수
조건
- 제재 아이디가 입력된 순서대로 제재 아이디를 찾는다.
제재 아이디를 찾는 방법
1. 유저 아이디를 순서대로 선택한다.
2. 첫 번째 제재 아이디에 맞는 유저 아이디를 찾는다.
4. 이미 찾은 제재 아이디를 자료구조에 저장한다.
3. 다음 제재 아이디로 넘어가서 1~3의 과정을 반복한다.
4. 제재 아이디의 수만큼 반복하였다면 한 경우의 수를 확인한 것이므로 해당 경우의 수를 저장한다.(Set을 사용하여 중복 제거)

중요한 점
- 제재 아이디 조합을 비트마스킹으로 저장(메모리 관리)
- 
**/

set<short> s;
short check = 0;
int len;
vector<string> bi,ui;

void dfs(int idx){
    if(idx==len){
        s.insert(check);
        return;
    }
    for(int i=0;i<ui.size();i++){
        //i번째 응모자가 이미 제제아이디라면 넘어가기
        if(check & 1 << i) continue;
        string su = ui[i];
        string sb = bi[idx];
        //제재 아이디와 유저 아이디 길이가 다르면 넘어가기
        if(su.size()!=sb.size()) continue;
        //아이디 확인
        bool avail=true;
        for(int k=0;k<su.size();k++){
            if(sb[k]=='*') continue;
            if(sb[k]!=su[k]){
                avail=false;
                break;
            }
        }
        //제재 아이디로 비트마스크에 저장, dfs가 끝나면 해당 제재 아이디를 제거하고 넘어가기
        if(avail){
            check |= 1 << i;
            dfs(idx+1);
            check &= ~(1 << i);
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    len = banned_id.size();
    bi = banned_id;
    ui = user_id;
    
    dfs(0);
    return answer = s.size();
}