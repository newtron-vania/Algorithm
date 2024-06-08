#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
using ll = long long;

int N, M;
int board[102][102];
bool check[102][102];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) 
    {
		for (int j = 0; j < M; j++) 
        {
			cin >> board[i][j];
		}
	}

	int zeroTime = 0;
	vector<int> cheese;

	while(true) 
    {

		int cheeseCnt = 0;
		queue<pair<int, int>> q; // 항상 0,0으로 시작
		q.push({ 0,0 });
		check[0][0] = 1;

		while (!q.empty()) 
        {
			auto cur = q.front();
			q.pop();
			for (int i = 0; i < 4; i++)
            {

				int nx = cur.first + dx[i];
				int ny = cur.second + dy[i];

				if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
				if (check[nx][ny]) continue;
				if (board[nx][ny] == 1) 
                {				
					//cout << "nx : " << nx << " ny : " << ny << "\n";
					check[nx][ny] = 1;
					board[nx][ny] = 0;
					cheeseCnt++;
				}
				else if(board[nx][ny] == 0)
                {
					check[nx][ny] = 1;
					q.push({ nx,ny });
				}
			}
		}

		cheese.push_back(cheeseCnt);


		for (int i = 0; i < N; i++) 
        {
			for (int j = 0; j < M; j++) 
            {
				check[i][j] = 0;
			}
		}

		
		if (cheeseCnt == 0)
        {
			break;
		}
		zeroTime++;
	}
	cout << zeroTime << "\n";
	cout << cheese[cheese.size() - 2];
}