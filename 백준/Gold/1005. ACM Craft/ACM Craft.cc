#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int tcc;

	cin >> tcc;

	while (tcc--) {
		int n, k; cin >> n >> k;
		vector<int> time(n);
		vector<int> maxTime(n);
		vector<int> degree(n);
		vector<vector<int>> adj(n);
		queue <int> q;

		for (int i = 0; i < n; i++)
			cin >> time[i];

		for (int i = 0; i < k; i++) {
			int to, des; cin >> to >> des;
			adj[to - 1].push_back(des - 1);
			degree[des - 1]++;
		}

		int tar; cin >> tar;

		for (int i = 0; i < n; i++)
			if (!degree[i]) {
				q.push(i);
				maxTime[i] = time[i];
			}

		while (!q.empty()) {
			int cur = q.front(); q.pop();

			if (degree[cur] < 1) {
				for (int i = 0; i < adj[cur].size(); i++) {
					int next = adj[cur][i];
					int nextTime = maxTime[cur] + time[next];

					if (maxTime[next] < nextTime) {
						maxTime[next] = nextTime;
						q.push(next);
					}
					degree[next]--;

				}
			}
		}

		cout << maxTime[tar - 1] << '\n';
	}

	return 0;
}