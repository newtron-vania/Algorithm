#include <bits/stdc++.h>

using namespace std;

long long solution(int n, vector<int>& times) 
{
    sort(times.begin(), times.end()); // 심사 시간을 오름차순으로 정렬
    
    long long left = 1; // 가능한 최소 시간
    long long right = (long long)times.back() * n; // 가능한 최대 시간
    long long answer = right; // 정답 초기화

    while (left <= right) 
    {
        long long mid = (left + right) / 2;
        long long total = 0; // mid 시간 내에 처리 가능한 사람 수

        for (int time : times) 
        {
            total += mid / time; // mid 시간 동안 해당 심사대에서 처리할 수 있는 사람 수
            if(total < 0)
            {
                total = numeric_limits<long long>::max();
                break;
            }
        }

        if (total >= n)  // mid 시간 내에 처리 가능한 사람 수가 n 이상이라면
        {
            answer = min(answer, mid); // 현재 시간을 정답으로 갱신
            right = mid - 1; // 더 작은 시간에서 정답을 찾기 위해 범위 축소
        } 
        else 
        {
            left = mid + 1; // 시간을 늘려서 더 많은 사람을 처리할 수 있도록 함
        }
    }

    return answer;
}

int main()
{
    int n, m;
    cin >> n >> m;
    
    vector<int> times(n, 0);
    for(int i =0; i < n; i++)
    {
        int time = 0;
        cin >> time;
        times[i] = time;
    }
    
    long long answer = solution(m, times);
    
    cout << answer << endl;
}