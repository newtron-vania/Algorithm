#include <bits/stdc++.h>
using namespace std;

int R, C, T;
int arr[51][51];
int add[51][51];
vector<int> cleaner;
int ans;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void getDust()
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (arr[i][j] > 0)
				ans += arr[i][j];
		}
	}
}

void runCleaner(int index)
{
	int row = cleaner[index];
	int dir = 0;
	pair<int, int> now = {row, 1};
	vector<pair<int, int>> endpoints = 
    {
		{row, C - 1},
		{0, C - 1},
		{R - 1, C - 1},
		{R - 1, 0},
		{0, 0}
    };

	int pre = 0, temp = 0;
	while (now.second != 0 || now.first != row)
	{
		temp = arr[now.first][now.second];
		arr[now.first][now.second] = pre;
		pre = temp;

		for (const auto &pt : endpoints)
		{
			if (now == pt)
				index == 0 ? dir = (dir + 3) % 4 : dir = (dir + 1) % 4;
		}

		now.second += dx[dir];
		now.first += dy[dir];
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C >> T;

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == -1)
				cleaner.push_back(i);
		}
	}

	for (int time = 0; time < T; time++)
	{
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				if (arr[i][j] <= 0)
					continue;

				int count = 0;
				for (int d = 0; d < 4; d++)
				{
					int ni = i + dy[d];
					int nj = j + dx[d];
					if (ni < 0 || ni >= R || nj < 0 || nj >= C || arr[ni][nj] == -1)
						continue;

					count++;
					add[ni][nj] += arr[i][j] / 5;
				}
				add[i][j] -= (arr[i][j] / 5) * count;
			}
		}

		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				arr[i][j] += add[i][j];
				add[i][j] = 0;
			}
		}

		runCleaner(0);
		runCleaner(1);
	}

	getDust();
	cout << ans << '\n';
	return 0;
}
