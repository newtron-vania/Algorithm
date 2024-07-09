#include <bits/stdc++.h>

using namespace std;

// 위상 정렬 알고리즘을 수행하는 함수
void topology_sort(int n, int m, vector<vector<int>>& graph, vector<int>& indegree)
{
    vector<int> result; // 결과를 저장할 벡터
    queue<int> q; // 노드를 처리하기 위한 큐

    // 진입 차수가 0인 노드를 큐에 삽입
    for (int i = 1; i <= n; ++i)
    {
        if (indegree[i] == 0) 
        {
            q.push(i);
        }
    }

    // 큐가 빌 때까지 반복
    while (!q.empty()) 
    {
        int now = q.front(); // 큐의 앞에 있는 노드를 꺼내기
        q.pop();
        result.push_back(now); // 결과에 추가

        // 해당 노드와 연결된 노드들의 진입 차수를 감소
        for (int node : graph[now])
        {
            indegree[node]--;
            if (indegree[node] == 0)
            {
                q.push(node);
            }
        }
    }

    // 결과 벡터의 크기가 n과 다르면 0 출력 (위상 정렬 불가)
    if (result.size() != n) 
    {
        cout << 0 << endl;
    } 
    else 
    {
        // 결과 출력
        for (int i : result)
        {
            cout << i << endl;
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m; // 노드와 간선의 개수 입력

    vector<vector<int>> graph(n + 1); // 그래프 초기화 (노드 간의 관계 저장)
    vector<int> indegree(n + 1, 0); // 진입 차수 초기화

    // 간선 정보 입력
    for (int i = 0; i < m; ++i) 
    {
        int k;
        cin >> k; // 현재 입력 받을 노드 수
        vector<int> tmp_list(k); // 임시 리스트
        for (int j = 0; j < k; ++j)
        {
            cin >> tmp_list[j]; // 임시 리스트에 노드 입력
        }
        for (int j = 1; j < k; ++j) 
        {
            int start = tmp_list[j - 1];
            int finish = tmp_list[j];
            graph[start].push_back(finish); // 그래프에 간선 추가
            indegree[finish]++; // 도착 노드의 진입 차수 증가
        }
    }

    topology_sort(n, m, graph, indegree); // 위상 정렬 함수 호출

    return 0;
}
