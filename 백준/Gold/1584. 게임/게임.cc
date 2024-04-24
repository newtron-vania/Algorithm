#include <bits/stdc++.h>

using namespace std;

struct point 
{
	int y;
	int x;
	int cost;
};

int main() 
{
	int dx[4] = { -1, 0, 1, 0 };
	int dy[4] = { 0, -1, 0, 1 };
	int N, M, ans = -1;
	int field[501][501] = { 0 };
	bool visit[501][501] = { false };

	cin >> N;
	while (N--) 
    {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if (x1 > x2) 
        {
			int temp = x1;
			x1 = x2;
			x2 = temp;
		}
		if (y1 > y2)
        {
			int temp = y1;
			y1 = y2;
			y2 = temp;
		}
		for (int i = x1; i <= x2; i++)
			for (int j = y1; j <= y2; j++)
				field[i][j] = 1;
	}	
	cin >> M;
	while (M--) 
    {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if (x1 > x2)
        {
			int temp = x1;
			x1 = x2;
			x2 = temp;
		}
		if (y1 > y2)
        {
			int temp = y1;
			y1 = y2;
			y2 = temp;
		}
		for (int i = x1; i <= x2; i++)
			for (int j = y1; j <= y2; j++)
				visit[i][j] = true;
	}

	deque<point> dq;
	dq.push_back({ 0,0,0 });
	visit[0][0] = true;

	while (!dq.empty()) 
    {
		int curX = dq.front().x;
		int curY = dq.front().y;
		int curCost = dq.front().cost;
		dq.pop_front();

		if (curX == 500 && curY == 500) 
        {
			ans = curCost;
			break;
		}
		for (int i = 0; i < 4; i++) 
        {
			if (curX + dx[i] >= 0 && curX + dx[i] <= 500
				&& curY + dy[i] >= 0 && curY + dy[i] <= 500
				&& !visit[curY + dy[i]][curX + dx[i]])
			{
				if (field[curY + dy[i]][curX + dx[i]] == 0)
					dq.push_front({ curY + dy[i], curX + dx[i], curCost });
				else 
					dq.push_back({ curY + dy[i], curX + dx[i], curCost + 1 });
				visit[curY + dy[i]][curX + dx[i]] = true;
			}
		}
	}
	cout << ans;
	return 0;
}