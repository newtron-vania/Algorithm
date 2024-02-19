#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX = 1e5;

int solution(int n, vector<int> cores) {
    if (n <= cores.size())
    {
        return n;
    }
    
    int size = cores.size();
    int minCore = MAX;
    int maxCore = 0;
    for (int core : cores)
    {
        minCore = min(minCore, core);
        maxCore = max(maxCore, core);
    }
    
    int left = minCore * (n / size);
    int right = maxCore * n;
        
        
    while (left <= right)
    {
        int mid = (left + right) / 2;
        int workCnt = size;
        int curWorkCnt = 0;
        
        
        for (int core : cores)
        {
            workCnt += (mid / core);
            if (mid % core == 0)
            {
                workCnt--;
                curWorkCnt++;
            }
        }
        
        int sum = workCnt + curWorkCnt;
        if (workCnt >= n)
        {
            right = mid - 1;
        }
        else if (sum < n)
        {
            left = mid + 1;
        }
        else
        {
            for (int i = 0; i < size; i++)
            {
                if (mid % cores[i] == 0)
                {
                    workCnt++;
                }
                if (workCnt == n)
                {
                    return i + 1;
                }
            }
        }
    }
    return 0;
}