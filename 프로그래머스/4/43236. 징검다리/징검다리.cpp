#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) 
{
    int answer = 0;
    int start = 1;
    int end = distance;
    int mid;
    int cnt, prev;
    
    sort(rocks.begin(), rocks.end());
    
    while(start <= end)
    {
        mid = (start+end)/2;
        cnt = 0;
        prev = 0;
        
        for (int i = 0; i < rocks.size(); ++i)
        {
            if(mid > rocks[i] - prev) ++cnt;
            else prev = rocks[i];
        }
        
        if(mid > distance - prev)
        {
            ++cnt;
        }
        
        
        if(cnt > n)
        {
            end = mid-1;
        }
        else
        {
            start = mid+1;
            answer = mid;
        }
    }
    return answer;
}