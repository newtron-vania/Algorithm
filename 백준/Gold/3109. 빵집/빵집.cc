#include <iostream>

using namespace std;

int dx[3] = {-1,0,1};
int R,C,cnt = 0;
string a;
int mat[10001][501];

bool dfs(int x, int y)
{
    mat[x][y] = 1;
    if(y == C - 1){
        cnt++;
        return true;
    }
    for(int k = 0 ; k < 3 ; k++)
    {
        if(x + dx[k] >= 0 && x + dx[k] < R && mat[x + dx[k]][y + 1] == 0)
        {
            if(dfs(x + dx[k],y + 1)) 
                return true;
        }
    }
    return false;
}

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> R >> C;
    
    for(int i  = 0 ; i < R ; i++)
    {
        cin >> a;
        for(int j = 0 ; j < C ;j++)
        {
            if(a[j] == '.')
            {
                mat[i][j] = 0;
            }
            else{
                mat[i][j] = 1;
            }
        }
    }

    for(int i = 0 ; i < R ;i++)
    {
        dfs(i,0);
    }
    cout << cnt;
}