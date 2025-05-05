#include <bits/stdc++.h>
using namespace std;

int arr[101][101];
int ans;
int dir_idx = 0;
int dx[4] = {1, 0, -1, 0}; // 오른쪽, 아래, 왼쪽, 위
int dy[4] = {0, 1, 0, -1};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n, k, l;
    cin >> n >> k;
    
    for(int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        arr[x][y] = 2; // 사과
    }
    
    cin >> l;
    queue<pair<int, char>> time;
    for(int i = 0; i < l; i++)
    {
        int x; char c;
        cin >> x >> c;
        time.push({x, c});
    }

    arr[1][1] = 1;    
    deque<pair<int, int>> dq;
    dq.push_back({1, 1});
    
    while(1)
    {
        ans++;
        int nRow = dq.back().first + dy[dir_idx];
        int nCol = dq.back().second + dx[dir_idx];
        if(nRow <= 0 || nRow > n || nCol <= 0 || nCol > n || arr[nRow][nCol] == 1) 
            break;

        if(arr[nRow][nCol] != 2)
        {
            arr[dq.front().first][dq.front().second] = 0;
            dq.pop_front();
        }
        arr[nRow][nCol] = 1;
        dq.push_back({nRow, nCol});

        if(!time.empty() && ans == time.front().first)
        {
            char ch = time.front().second;
            if(ch == 'D')
                dir_idx = (dir_idx + 1) % 4;
            else
                dir_idx = (dir_idx - 1 + 4) % 4;
            time.pop();
        }
    }
    cout << ans << '\n';
}
