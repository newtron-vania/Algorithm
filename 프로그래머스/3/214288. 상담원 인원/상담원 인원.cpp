#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

// 각 유형 별 상담원 수에 따른 대기 시간을 계산하는 함수
int CaculateTime(int type, int count, vector<vector<int>>& reqs);

// 메인 솔루션 함수
int solution(int k, int n, vector<vector<int>> reqs) {
    int answer = 0; // 최종 답
    int max_num = n-k+1; // 최대 상담원 수
    vector<vector<vector<int>>> req_sep(k+1, vector<vector<int>>()); // 요청을 유형별로 분리하여 저장

    // 각 요청을 유형별로 분류하여 저장
    for(vector<int> req : reqs)
    {
        int start_time = req[0];
        int end_time = req[1];
        int type = req[2];
        req_sep[type].push_back({end_time, start_time});
    }
    
    // 각 유형별 상담원 수에 따른 대기 시간을 계산하여 저장
    int* dp = new int[(k+1) * max_num]; 
    for(int i = 1; i <= k; i++)
    {
        for(int j = 1; j <= max_num; j++)
        {
            dp[(max_num*i) + (j-1)] = CaculateTime(i, j, req_sep[i]);
        }
    }
    
    int sur_num = n-k; // 남은 상담원 수
    int* ans_arr = new int[k+1] {0,}; // 각 유형별 배정된 상담원 수를 저장

    // 남은 상담원을 배치하는 과정
    while(sur_num > 0)
    {
        int max_diff = 0; // 최대 시간 차이
        int next_type = 1; // 다음에 상담원을 추가할 유형
        for(int type = 1; type <=k; type++)
        {
            int count = ans_arr[type];
            int diff =  dp[(max_num * type) + count] - dp[(max_num * type) + (count+1)];
            
            if(max_diff < diff)
            {
                max_diff = diff;
                next_type = type;
            }
        }
        
        if(max_diff == 0)
            break;
        
        ans_arr[next_type] += 1; // 상담원 추가
        sur_num--;
    }
    
    // 최종 대기 시간 계산
    for(int type = 1; type <=k; type++)
    {
        answer += dp[(max_num * type) + ans_arr[type]];
    }
    
    delete[] ans_arr;
    delete[] dp;
    return answer;
}

// 각 유형별 상담원 수에 따른 대기 시간을 계산하는 함수 구현
int CaculateTime(int type, int count, vector<vector<int>>& reqs)
{
    priority_queue<int, vector<int>, greater<>> pq; // 끝나는 시간을 기준으로 우선순위 큐 사용
    int result_time = 0; // 결과 시간
    
    for(const vector<int>& req : reqs)
    {
        if(pq.size() < count) // 상담원이 더 필요한 경우
        {
            pq.push(req[1] + req[0]);
        }
        else // 상담원이 충분한 경우
        {
            int end_time = pq.top();
            pq.pop();
            
            int time = max(0, end_time - req[1]);
            result_time += time;
            
            pq.push(max(req[1], end_time) + req[0]);
        }

    }
    return result_time;
}