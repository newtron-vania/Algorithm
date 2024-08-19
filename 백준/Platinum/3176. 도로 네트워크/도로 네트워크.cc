#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

int node_num;
const int TREE_HIGHT = 20;
const int MAX_NUM = 100000;
int depth[MAX_NUM];
int parent[MAX_NUM + 1][TREE_HIGHT];
int min_road[MAX_NUM + 1][TREE_HIGHT];
int max_road[MAX_NUM + 1][TREE_HIGHT];
vector<pair<int, int>> adj[MAX_NUM + 1];

// 부모 노드와 도로 길이를 계산하는 재귀 함수
void FindParent(int par, int now, int dep, int road_len)
{
    depth[now] = dep;
    parent[now][0] = par;
    min_road[now][0] = max_road[now][0] = road_len;

    // 현재 노드와 연결된 자식 노드들을 탐색
    for (int i = 0; i < adj[now].size(); ++i)
    {
        if (adj[now][i].first != par)
        {
            FindParent(now, adj[now][i].first, dep + 1, adj[now][i].second);
        }
    }
    return;
}

// 두 노드 사이의 최소 및 최대 도로 길이를 찾는 함수
pair<int, int> FindMinMaxRoad(int a, int b)
{
    int min_result = 1000001, max_result = 0;

    // 두 노드의 깊이가 다르면, 깊이를 맞춰줌
    if (depth[a] != depth[b])
    {
        if (depth[a] < depth[b]) // 깊이가 다르다면 a가 항상 더 깊게 설정
        {
            swap(a, b);
        }

        int dif = depth[a] - depth[b];

        // 깊이 차이를 조정하며 최소/최대 값을 갱신
        for (int i = 0; dif > 0; ++i)
        {
            if (dif % 2 == 1)
            {
                min_result = min(min_result, min_road[a][i]);
                max_result = max(max_result, max_road[a][i]);
                a = parent[a][i];
            }
            dif = dif >> 1;
        }
    }

    // 두 노드가 동일한 조상에 도달할 때까지 탐색
    if (a != b)
    {
        for (int k = TREE_HIGHT - 1; k >= 0; --k)
        {
            if (parent[a][k] != 0 && parent[a][k] != parent[b][k])
            {
                min_result = min(min_result, min_road[a][k]);
                min_result = min(min_result, min_road[b][k]);

                max_result = max(max_result, max_road[a][k]);
                max_result = max(max_result, max_road[b][k]);
                a = parent[a][k];
                b = parent[b][k];
            }
        }

        // 마지막으로 공통 부모 노드에서 값을 갱신
        min_result = min(min_result, min_road[a][0]);
        min_result = min(min_result, min_road[b][0]);

        max_result = max(max_result, max_road[a][0]);
        max_result = max(max_result, max_road[b][0]);
    }

    return make_pair(min_result, max_result);
}

int main()
{
    scanf("%d", &node_num);

    int a, b, road;
    for (int i = 0; i < node_num - 1; ++i)
    {
        scanf("%d %d %d", &a, &b, &road);
        adj[a].push_back(make_pair(b, road));
        adj[b].push_back(make_pair(a, road));
    }

    memset(parent, 0, sizeof(parent));
    memset(min_road, 1000001, sizeof(min_road));
    memset(max_road, 0, sizeof(max_road));

    // 루트 노드부터 부모 노드 찾기 시작
    FindParent(0, 1, 0, 0);

    // 부모, 최소 도로, 최대 도로 값 갱신
    for (int k = 1; k < TREE_HIGHT; ++k)
    {
        for (int idx = 2; idx <= node_num; ++idx)
        {
            if (parent[idx][k - 1] != 0)
            {
                parent[idx][k] = parent[parent[idx][k - 1]][k - 1];
                min_road[idx][k] = min(min_road[parent[idx][k - 1]][k - 1], min_road[idx][k - 1]);
                max_road[idx][k] = max(max_road[parent[idx][k - 1]][k - 1], max_road[idx][k - 1]);
            }
        }
    }

    int pair_num;
    pair<int, int> result;
    scanf("%d", &pair_num);

    while (pair_num--)
    {
        scanf("%d %d", &a, &b);
        result = FindMinMaxRoad(a, b);
        printf("%d %d\n", result.first, result.second);
    }

    return 0;
}
