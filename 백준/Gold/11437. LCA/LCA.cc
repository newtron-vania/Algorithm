#include <bits/stdc++.h>

using namespace std;

int N, M;
int u, v;
queue<int> q;
vector<int> node[50001];
bool check[50001];
int parent[50001];
int depth[50001];

int LCA(int u, int v)
{
	// v가 u보다 더 깊은 노드로 세팅
	if (depth[u] > depth[v]) swap(u, v);
	
	// 두 노드의 깊이가 같아질때까지 v노드는 위로 거슬러 올라감
	while (depth[u] != depth[v]) v = parent[v];
	
	// 두 노드가 같아질때 까지 위로 거슬러 올라감
	while (u != v)
	{
		u = parent[u];
		v = parent[v];
	}
	return u; // LCA 리턴
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	// 해당노드에 연결된 노드 push
	for (int i = 0; i < N-1; i++)
	{
		cin >> u >> v;
		node[u].push_back(v);
		node[v].push_back(u);
	}

	check[1] = true;
	q.push(1); // 트리의 루트 

	while (!q.empty())
	{
		int x = q.front(); // 부모 노드
		q.pop();

		for (int i = 0; i < node[x].size(); i++)
		{
			if (!check[node[x][i]]) // 현재노드를 방문한적 없다면
			{
				depth[node[x][i]] = depth[x] + 1; // 깊이 +1
				check[node[x][i]] = true; // 방문표시
				parent[node[x][i]] = x; // 부모노드 입력
				q.push(node[x][i]); // 큐에 추가
			}
		}
	}

	cin >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> u >> v;
		cout << LCA(u, v) << '\n';
	}

}