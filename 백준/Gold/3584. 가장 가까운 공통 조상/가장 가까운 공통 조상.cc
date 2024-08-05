#include <iostream>
#include <vector>

using namespace std;

const int MAX = 10001;
int parent[MAX];
bool visited[MAX];
int t, n, a, b, u, v;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> t; // 테스트 케이스 수
    while (t--)
    {
        cin >> n; // 노드의 수

        // 초기화
        for (int i = 1; i <= n; i++)
        {
            visited[i] = false;
            parent[i] = i; // 자기 자신을 부모로 초기화
        }

        // 간선 정보 입력
        for (int i = 0; i < n - 1; i++)
        {
            cin >> a >> b;
            parent[b] = a; // b의 부모를 a로 설정
        }

        cin >> u >> v; // 찾아야 하는 두 노드

        // 첫 번째 노드의 조상 방문 표시
        visited[u] = true;
        while (u != parent[u])
        {
            u = parent[u];
            visited[u] = true;
        }

        // 두 번째 노드의 조상 중 방문된 조상 찾기
        while (!visited[v])
        {
            v = parent[v];
        }

        cout << v << "\n"; // 가장 가까운 공통 조상 출력
    }

    return 0;
}
