#include <string>
#include <vector>

using namespace std;

// 투 포인터 누적합
int solution(vector<int> cookies) {
    int answer = 0;

    for(int i = 0; i < cookies.size(); i++)
    {
        int left = i;
        int right = i+1;
        // left ~ i 의 누적합
        int ls = cookies[left];
        // i ~ right 누적합
        int rs = cookies[right];
        
        while(true)
        {
            // 조건에 적합
            if(ls == rs && answer < ls)
            {
                answer = ls;
            }
            // 우측이 더 클 경우 좌측 누적합 증가
            else if(ls <= rs && left > 0)
            {
                ls += cookies[--left];
            }
            // 좌측이 더 클 경우 우측 누적합 증가
            else if(ls >= rs && right < cookies.size() - 1)
            {
                rs += cookies[++right];
            }
            // 범위를 벗어날 경우 다음 i로 이동
            else{
                break;
            }
        }
    }

    
    return answer;
}