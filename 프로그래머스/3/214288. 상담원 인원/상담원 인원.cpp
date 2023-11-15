#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;
/**
유형 별 x명일 때의 최단시간 = 우선순위 큐를 통해 끝나는 시간을 우선순위로 정렬
DP를 통해 상담원 인수별로 시간을 계산 -> 각 유형병로 인원수가 1명씩 늘어날 때마다 줄어드는 대기시간이 가장 큰 쪽에 인원수를 추가한다.
**/
int CaculateTime(int type, int count, vector<vector<int>>& reqs);

int solution(int k, int n, vector<vector<int>> reqs) {
    int answer = 0;
    int max_num = n-k+1;
    vector<vector<vector<int>>> req_sep(k+1, vector<vector<int>>()); 
    for(vector<int> req : reqs)
    {
        int start_time = req[0];
        int end_time = req[1];
        int type = req[2];
        req_sep[type].push_back({end_time, start_time});
    }
    
    int* dp = new int[(k+1) * max_num]; 
    
    for(int i = 1; i <= k; i++)
    {
        for(int j = 1; j <= max_num; j++)
        {
            dp[(max_num*i) + (j-1)] = CaculateTime(i, j, req_sep[i]);
            //cout << dp[(max_num*i) + (j-1)] << " ";
        }
        //cout << endl;
    }
    
    
    int sur_num = n-k;
    int* ans_arr = new int[k+1] {0,};

    while(sur_num > 0)
    {
        int max_diff = 0;
        int next_type = 1;
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
        
        ans_arr[next_type] += 1;
        sur_num--;
    }
    
    for(int type = 1; type <=k; type++)
    {
        answer += dp[(max_num * type) + ans_arr[type]];
    }
    
    delete[] ans_arr;
    delete[] dp;
    return answer;
}

int CaculateTime(int type, int count, vector<vector<int>>& reqs)
{
    priority_queue<int, vector<int>, greater<>> pq;
    int result_time = 0;
    for(const vector<int>& req : reqs)
    {
        if(pq.size() < count)
        {
            pq.push(req[1] + req[0]);
        }
        else
        {
            int end_time = pq.top();
            pq.pop();
            int time = max(0, end_time - req[1]);
            //if(req[1] > p_req[0]) next_end = req[1] + req[0] ? p_req[0] + req[0]
            result_time += time;
            
            pq.push(max(req[1], end_time) + req[0]);
        }

    }
    return result_time;
}