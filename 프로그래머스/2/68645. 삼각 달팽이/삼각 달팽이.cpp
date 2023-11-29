#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n)
{
    vector<vector<int>> MAP(n + 1, vector<int>(n + 1));
    vector<int> answer;
    int Max_Num = (n * (n + 1)) / 2;
    int Top = 1;
    int Bottom = n;
    int Left = 1;
    int Right = 0;
    int Num = 1;
    int State = 0;
    while (Num <= Max_Num)
    {
        if (State == 0)
        {
            for (int i = Top; i <= Bottom; i++) MAP[i][Left] = Num++;
            Top++;
            Left++;
            State = 1;
        }
        else if (State == 1)
        {
            for (int i = Left; i <= Bottom - Right; i++) MAP[Bottom][i] = Num++;
            Bottom--;
            State = 2;
        }
        else if (State == 2)
        {
            for (int i = Bottom; i >= Top; i--) MAP[i][i - Right] = Num++;
            Right++;
            Top++;
            State = 0;
        }
    }
 
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            answer.push_back(MAP[i][j]);
        }
    }
    
    return answer;
}