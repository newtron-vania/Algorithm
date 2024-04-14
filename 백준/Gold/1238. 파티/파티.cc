#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;
int dist_x_to_n[1001];
vector<int> dist[2];
vector<pair<int, int>> graph[2][1001];
int n, m, x;


void dijkstra(int k) 
{
	dist[k][x] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push({0,x});

	while (!q.empty()) 
    {
		int d = q.top().first;
		int now = q.top().second;
		q.pop();

		if (d > dist[k][now]) continue;

		for (int i = 0; i < graph[k][now].size(); i++) 
        {
			int next = graph[k][now][i].second;
			int next_d = d + graph[k][now][i].first;

			if (next_d < dist[k][next]) 
            {
				dist[k][next] = next_d;
				q.push({ next_d,next });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	fill_n(dist_x_to_n, 1001, INF);

	cin >> n >> m >> x;

	for (int i = 0; i < m; i++) 
    {
		int a, b, t;
		cin >> a >> b >> t;
		graph[0][a].push_back({t,b});
		graph[1][b].push_back({ t,a });
	}

	dist[0].resize(n + 1, INF);
	dist[1].resize(n + 1, INF);

	dijkstra(0);
	dijkstra(1);

	int result = 0;

	for (int i = 1; i <= n; i++) 
    {
		result = max(result, dist[0][i] + dist[1][i]);
	}

	cout << result << '\n';

	return 0;
}