#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 순서롤 무조건 (하,좌,우,상) 해야함
int dx[] = {1,0,0,-1};
int dy[] = {0,-1,1,0};

// 각 인덱스에 맞는 문자 매핑
char dir[] = {'d','l','r','u'};

// 3차원으로 방문 배열을 만들어줘야함
bool visited[51][51][2501];

// 정답 경로
string result = "";

// 도착지 전역변수화
int endX;
int endY;

 // 맵의 크기
int nn;
int mm;

// 정답이 구해졌으면 더이상 DFS를 못하도록 하기 위한 플래그
bool finish = false;

void dfs(int x, int y, int k, string cnt)
{
    if(finish) return;
    
    // k = 0 일때 해당 자리가 도착 지점이면 성공한 것
    if(k == 0)
    {
        if(x == endX && y == endY)
        {
            finish = true;
            result = cnt;
        }
        return;
    }
    
    for(int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx > nn || ny > mm || nx < 1 || ny < 1 || visited[nx][ny][k-1]) 
            continue;

        visited[nx][ny][k-1] = true;

        dfs(nx,ny,k-1,cnt + dir[i]);
        if(finish) return;
    }
}
string solution(int n, int m, int x, int y, int r, int c, int k) 
{
    string answer = "";
    nn = n;
    mm = m;
    endX = r;
    endY = c;
    dfs(x,y,k,"");
    answer = result.empty() ? "impossible" : result;
    return answer;
}