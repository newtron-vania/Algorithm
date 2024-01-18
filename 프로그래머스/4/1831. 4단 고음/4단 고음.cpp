#include<math.h>

int answer;

void dfs(int value, int cnt){
    
    if(value < 3 || ((int)(log(value) / log(3)) << 1) < cnt)
        return; 
    if(value == 3)
    {
        if(cnt == 2) answer++;
        return;
    }
    
    if(value % 3 == 0 && cnt >= 2){ 
        dfs(value / 3, cnt - 2); 
    }
    dfs(value - 1, cnt + 1); 
    
}

int solution(int n) {
    answer = 0;
    dfs(n - 2, 2); // 2는 현재 + 의 개수, n-2는 최대 음 높이
    
    return answer;
}