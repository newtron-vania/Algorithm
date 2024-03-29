#include <string>
#include <vector>

using namespace std;

const int MAX = 15;
int col[MAX];

// dfs

bool check(int level)
{
    for(int i = 0; i < level; i++)
        // 대각선이거나 같은 라인
        //col[i]가 의미하는 것이 X좌표, i가 의미하는것이 Y좌표이므로 차이가 일정하다면 대각선에 있다고 볼 수 있다.
        if(col[i] == col[level] || abs(col[level] - col[i]) == level - i)
            return false;
    return true;
}

void nqueen(int x, int N, int& total)
{
    if(x == N)
    {
        total++;
        return;
    }
    for(int i = 0; i < N; i++)
    {
        // 해당 위치에 퀸을 배치
        col[x] = i; 
        
        // 유효하다면 다음행의 퀸 배치, 유효하지않다면 다른 위치로 퀸 배치 변경
        if(check(x)) 
            nqueen(x+1, N, total);
    }
}

int solution(int n)
{
    int answer = 0;
    
    nqueen(0, n, answer);
    
    return answer;
}