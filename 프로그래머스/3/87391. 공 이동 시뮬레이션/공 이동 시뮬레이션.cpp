#include <bits/stdc++.h>

using namespace std;

long long solution(int n, int m, int x, int y, vector<vector<int>> queries) 
{
    long long x1 = x, y1 = y;
    long long x2 = x, y2 = y;
    
    for (int i = queries.size() - 1; i >= 0; i--) 
    {
        int dir = queries[i][0];
        int size = queries[i][1];
        
        switch (dir) 
        {
            case 0: // 오른쪽 이동
                if (y1 != 0) 
                {
                    y1 += size;
                }
                y2 = min(y2 + size, (long long)m - 1);
                if (y1 > m - 1) 
                {
                    return 0;
                }
                break;
            case 1: // 왼쪽 이동
                if (y2 != m - 1) 
                {
                    y2 -= size;
                }
                y1 = max(y1 - size, 0LL);
                if (y2 < 0) 
                {
                    return 0;
                }
                break;
            case 2: // 아래로 이동
                if (x1 != 0) 
                {
                    x1 += size;
                }
                x2 = min(x2 + size, (long long)n - 1);
                if (x1 > n - 1) 
                {
                    return 0;
                }
                break;
            case 3: // 위로 이동
                if (x2 != n - 1) 
                {
                    x2 -= size;
                }
                x1 = max(x1 - size, 0LL);
                if (x2 < 0) 
                {
                    return 0;
                }
                break;
        }
    }

    return (x2 - x1 + 1) * (y2 - y1 + 1);
}
