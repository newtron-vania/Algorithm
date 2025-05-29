#include <bits/stdc++.h> 

using namespace std;

int getID(char c)
{
	if (c <= 'Z')
	{
		return c - 'A';
	}
	return c - 'a' + 26;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	int c[52][52];
	int f[52][52];
	vector<int> map[52];

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		char u, v;
		int w;
		cin >> u >> v >> w;

		int U = getID(u), V = getID(v);
		map[U].push_back(V);
		map[V].push_back(U);
		c[U][V] += w;
		c[V][U] += w;
	}

	int maximumFlow = 0, s = 0, t = 25;
	while (true)
	{
		int visit[52]{};
		fill(visit, visit + 52, -1);

		queue<int> q;
		q.push(s);
		while (!q.empty())
		{
			int front = q.front();
			q.pop();

			for (int i = 0; i < map[front].size(); i++)
			{
				int next = map[front][i];
				if (c[front][next] - f[front][next] > 0 && visit[next] == -1)
				{
					q.push(next);
					visit[next] = front;

					if (next == t)
					{
						break;
					}
				}
			}
		}

		if (visit[t] == -1)
		{
			break;
		}

		int flow = 1e9;

		for (int i = t; i != s; i = visit[i])
		{
			flow = min(flow, c[visit[i]][i] - f[visit[i]][i]);
		}

		for (int i = t; i != s; i = visit[i])
		{
			f[visit[i]][i] += flow;
			f[i][visit[i]] -= flow;
		}

		maximumFlow += flow;
	}

	cout << maximumFlow;
}
