#include <string>
#include <vector>
#include <cmath>
#include <limits>
 
using namespace std;
 
vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls)
{
    vector<int> answer;
    
    for(int i = 0; i < balls.size(); i++)
    {
        float result = numeric_limits<float>::max();
        float temp = 0.f;
        
        vector<int> ball = balls[i];
        
        // 상단 벽에 맞는 경우 (x = 0)
        if (!(startY == ball[1] && startX > ball[0]))
        {
            int temp_x = ball[0] * -1, temp_y = ball[1];
            temp = pow(abs(startX - temp_x), 2) + pow(abs(startY - temp_y), 2);
            result = min(result, temp);
        }
        
        // 좌측 벽에 맞는 경우 (y = 0)
        if (!(startX == ball[0] && startY > ball[1]))
        {
            int temp_x = ball[0] , temp_y = ball[1] * -1;
            temp = pow(abs(startX - temp_x), 2) + pow(abs(startY - temp_y), 2);
            result = min(result, temp);
        }
        
        // 하단 벽에 맞는 경우 (x = m)
        if (!(startY == ball[1] && startX < ball[0]))
        {
            int temp_x = 2 * m - ball[0], temp_y = ball[1];
            temp = pow(abs(temp_x - startX), 2) + pow(abs(temp_y - startY), 2);
            result = min(result, temp);
        }
        
        // 우측 벽에 맞는 경우 (y = n)
        if (!(startX == ball[0] && startY < ball[1]))
        {
            int temp_x = ball[0] , temp_y = 2 * n - ball[1];
            temp = pow(abs(startX - temp_x), 2) + pow(abs(temp_y - startY), 2);
            result = min(result, temp);
        }
        
        answer.push_back(result);
    }
    
    return answer;
}
