#include <iostream>
#include <cmath>
using namespace std;

int N;
int num = 0;
int* chess_list;

bool check(int cnt) 
{
    for (int j = 0; j < cnt; j++) 
    {
        if ((chess_list[j] == chess_list[cnt]) || (abs(chess_list[cnt] - chess_list[j]) == cnt - j)) {
            return false;
        }
    }
    return true;
}

void n_queen(int cnt) 
{
    if (N <= cnt)
    {
        num++;
    } 
    else 
    {
        for (int i = 0; i < N; i++)
        {
            chess_list[cnt] = i;
            if (check(cnt)) 
            {
                n_queen(cnt + 1);
            }
        }
    }
}

int main()
{
    cin >> N;
    chess_list = new int[N];
    n_queen(0);
    cout << num << endl;
    delete[] chess_list;
    return 0;
}
