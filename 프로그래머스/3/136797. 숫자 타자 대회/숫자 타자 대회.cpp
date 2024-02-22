#include <string>
#include <vector>
#include <cmath>
using namespace std;

struct Point{
    int x,y;
};

char map[4][3] = {{'1','2','3'},
                {'4','5','6'},
                {'7','8','9'},
                {'*','0','#'}};
vector<Point> input; // 숫자 입력 순서
int dp[100001][10][10]; // dp 배열


// 두 점 사이의 최소 가중치를 계산하는 함수
int getWeight(Point pos, Point target){
    int sx = pos.x;
    int sy = pos.y;

    int x = target.x;
    int y = target.y;
	
    // 두 점이 동일할 때(정지)
    if(sx == x && sy == y) return 1;
	
    // 상하좌우(일직선) 일 때
    if(sx == x || sy == y) return abs((sx-x)*2 + (sy-y)*2);
	
    // 대각선일때
    if(abs(sx - x) == abs(sy - y)) return abs(sx-x)*3;
	
    // 그 외 일 때
    int nx = abs(sx-x);
    int ny = abs(sy-y);
    int diag = min(nx,ny);
    int line = max(nx,ny);

    return diag *3 + (line-diag)* 2;
}

// 시뮬레이션을 돌림
int startGame(Point left, Point right, int idx){
    if(idx >= input.size()) return 0;// 인덱스를 다 돌았으면 종료

    
    // left와 right의 좌표가 동일하면 안됨
    if(left.x == right.x && left.y == right.y) return 9999999;
    
    int l_num = map[left.x][left.y]-'0'; // 왼손의 현재 번호
    int r_num = map[right.x][right.y]-'0'; // 오른손의 현재 번호 
    
    
    // dp 배열에 저장되어 있는 값이 있으면 바로 반환
    if(dp[idx][l_num][r_num] != 0) return dp[idx][l_num][r_num];
    
    //각 손으로 위치로 갔을 때의 최소 비용
    int l_weight = getWeight(left,input[idx]);
    int r_weight = getWeight(right,input[idx]);
    
    // 해당 위치로 갔을 경우 최소 비용의 합
    int v1 = l_weight + startGame(input[idx],right,idx+1);
    int v2 = r_weight + startGame(left,input[idx],idx+1);
	
    // 더 작은 값을 dp 배열로 저장
    return dp[idx][l_num][r_num] = min(v1,v2);
}

int solution(string numbers) {
    int answer = 0;
    for(int k = 0; k < numbers.length(); k++){
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 3; j++)
            	// 입력값의 좌표를 찾아서 input에 저장
                if(map[i][j] == numbers[k]) input.push_back({i,j});
    }
    Point left = {1,0}; // 왼손 초기 위치
    Point right = {1,2}; // 오른손 초기 위치
    answer = startGame(left,right,0);
    return answer;
}