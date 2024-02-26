#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<vector<int>> data) {
    int answer = 0;
    
    vector<int> xdata;
    vector<int> ydata;
    
    for(vector<int> d : data)
    {
        xdata.push_back(d[0]);
        ydata.push_back(d[1]);
    }
    
    set<int> xset(xdata.begin(), xdata.end());
    set<int> yset(ydata.begin(), ydata.end());
    
    xdata.clear();
    ydata.clear();
    
    xdata = vector(xset.begin(), xset.end());
    ydata = vector(yset.begin(), yset.end());
    
    vector<vector<int>> S(n, vector<int>(n, 0));

    for(auto& d : data)
    {
        int x = find(xdata.begin(), xdata.end(), d[0]) - xdata.begin();
        int y = find(ydata.begin(), ydata.end(), d[1]) - ydata.begin();
        
        d[0] = x;
        d[1] = y;
        
        S[x][y] = 1;
    }
    
    //구간합 계산
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            S[i][j] += (i - 1 >= 0 ? S[i - 1][j] : 0)
                    + (j - 1 >= 0 ? S[i][j - 1] : 0)
                    - (i - 1 >= 0 && j - 1 >= 0 ? S[i - 1][j - 1] : 0);
        }
    }
    
    int x, y, nx, ny;
    for(int i = 0; i < n; i++)
    {
        x = data[i][0];
        y = data[i][1];
        for(int j = i + 1; j < n; j++)
        {
            nx = data[j][0];
            ny = data[j][1];
            //1. x or y 가 같음 == 직사각형이 아님
            if(x == nx || y == ny) continue;
            
            //2. 내부 쐐기 확인
            
            int startX = min(x, nx);
            int startY = min(y, ny);
            int endX = max(x, nx);
            int endY = max(y, ny);
            
            if(startX + 1 > endX - 1 || startY + 1 > endY - 1)
            {
                answer++;
            }
            else if(S[endX - 1][endY - 1] 
                    - S[endX - 1][startY] 
                    - S[startX][endY - 1] 
                    + S[startX][startY] <= 0)
            {
                answer++;
            }
        }
    }
    return answer;
}