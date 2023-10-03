#include <string>
#include <map>
#include <iostream>
using namespace std;

int solution(string dirs) {
    int answer = 0;
    //방문 노드 -> 도착노드
    map<pair<pair<int,int>,pair<int,int>>, bool> m;
    int x=0, y=0, nx=0, ny=0;
    for(int i=0; i<dirs.length(); i++) {
        
        if(dirs[i]=='U' && ny+1<=5) {
            ny++;
        } else if(dirs[i]=='D' && ny-1>=-5) {
            ny--;
        } else if(dirs[i]=='R' && nx+1<=5) {
            nx++;
        } else if(dirs[i]=='L' && nx-1>=-5) {
            nx--;
        } else { 
            continue;
        }
        
        // 현재좌표와 다음좌표을 통해 걸어본 적 있는 길인지 검사
        if(m.find(make_pair(make_pair(x,y),make_pair(nx,ny)))==m.end() && 
           m.find(make_pair(make_pair(nx,ny),make_pair(x,y)))==m.end()) {
            m.insert({make_pair(make_pair(x,y),make_pair(nx,ny)), true});
            answer++;
        }
           x=nx; y=ny; // 현재좌표를 다음좌표로 갱신
    }
    
    return answer;
}