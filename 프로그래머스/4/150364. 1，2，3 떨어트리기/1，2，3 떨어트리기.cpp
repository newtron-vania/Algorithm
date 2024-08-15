#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

// 간선 정보를 저장하는 해시맵 (그래프 표현)
unordered_map<int, vector<int>> edge_dict;

// 트리 구조를 저장하는 해시맵 (노드의 자식 정보 및 방문 인덱스 관리)
unordered_map<int, pair<int, vector<int>>> tree_dict;

// 방문 여부를 확인하기 위한 벡터
vector<bool> visited;

// 노드를 방문한 순서 목록
vector<int> order_list;

// 최종 답안을 저장하는 벡터
vector<int> answer;

// 각 리프 노드의 방문 횟수를 저장하는 해시맵
unordered_map<int, int> leaf_cap_dict;

// 리프 노드가 목표값을 달성했는지 여부를 저장하는 해시맵
unordered_map<int, bool> is_leaf_succeeded;

// 깊이 우선 탐색(DFS) 함수
vector<int> dfs(int node) {
    vector<int> child_list;
    
    // 현재 노드의 자식 노드를 탐색
    for (int child : edge_dict[node]) {
        if (visited[child]) continue; // 이미 방문한 노드는 건너뜀
        visited[child] = true; // 자식 노드를 방문했음을 표시
        child_list.push_back(child); // 자식 노드를 리스트에 추가
    }

    // 리프 노드인 경우, 현재 노드를 리턴
    if (child_list.empty()) return {node};

    // 자식 노드들을 오름차순으로 정렬
    sort(child_list.begin(), child_list.end());
    
    // 현재 노드에 대해 자식 노드 리스트와 방문 인덱스(초기 0)를 저장
    tree_dict[node] = {0, child_list};

    vector<int> leaf_list;
    
    // 자식 노드를 재귀적으로 탐색
    for (int child : child_list) {
        vector<int> child_leaves = dfs(child);
        leaf_list.insert(leaf_list.end(), child_leaves.begin(), child_leaves.end());
    }
    
    // 자식 노드들의 리프 노드 목록을 리턴
    return leaf_list;
}

// 트리에서 순환 탐색을 통해 리프 노드를 찾는 함수
int search(int node) {
    // 리프 노드에 도달했을 경우 해당 노드를 리턴
    if (tree_dict.find(node) == tree_dict.end()) return node;

    int idx = tree_dict[node].first;
    tree_dict[node].first = (tree_dict[node].first + 1) % tree_dict[node].second.size();
    
    // 현재 노드의 자식 노드를 재귀적으로 탐색
    return search(tree_dict[node].second[idx]);
}

// 메인 솔루션 함수
vector<int> solution(vector<vector<int>> edges, vector<int> target) {
    int n = target.size();
    visited.assign(n, false); // 방문 여부를 초기화
    visited[0] = true; // 루트 노드를 방문으로 표시

    // 간선 정보를 edge_dict에 저장
    for (const auto& edge : edges) {
        int a = edge[0], b = edge[1];
        edge_dict[a-1].push_back(b-1);
        edge_dict[b-1].push_back(a-1);
    }

    // DFS를 통해 리프 노드들을 얻음
    vector<int> leaf_list = dfs(0);

    // 리프 노드들에 대해 초기값 설정
    for (int leaf : leaf_list) {
        leaf_cap_dict[leaf] = 0;
        is_leaf_succeeded[leaf] = (target[leaf] == 0);
    }

    // 목표를 달성할 때까지 순환
    while (true) {
        bool all_succeeded = true;
        // 모든 리프 노드가 목표값을 달성했는지 확인
        for (const auto& [leaf, succeeded] : is_leaf_succeeded) {
            if (!succeeded) {
                all_succeeded = false;
                break;
            }
        }
        if (all_succeeded) break;

        // 현재 탐색할 노드를 찾음
        int cur_node = search(0);
        leaf_cap_dict[cur_node]++; // 해당 노드의 방문 횟수를 증가시킴

        // 목표값을 초과한 경우, 실패(-1 리턴)
        if (leaf_cap_dict[cur_node] > target[cur_node]) return {-1};
        
        // 목표를 달성할 수 있는지 확인
        if (!is_leaf_succeeded[cur_node] && leaf_cap_dict[cur_node] * 3 >= target[cur_node]) {
            is_leaf_succeeded[cur_node] = true;
        }

        order_list.push_back(cur_node); // 방문 순서 리스트에 추가
    }

    // 최종 답안을 구성
    answer.assign(order_list.size(), 0);
    for (int leaf : leaf_list) {
        vector<int> leaf_result;
        int sur_cap = target[leaf] - leaf_cap_dict[leaf];

        // 각 리프 노드의 결과를 1, 2, 3으로 나눠 채움
        leaf_result.insert(leaf_result.end(), leaf_cap_dict[leaf] - sur_cap % 2 - sur_cap / 2, 1);
        leaf_result.insert(leaf_result.end(), sur_cap % 2, 2);
        leaf_result.insert(leaf_result.end(), sur_cap / 2, 3);

        // order_list에 맞게 답을 채워 넣음
        for (int idx = 0; idx < order_list.size(); idx++) {
            if (order_list[idx] == leaf) {
                answer[idx] = leaf_result[0];
                leaf_result.erase(leaf_result.begin());
            }
        }
    }

    return answer; // 최종 답안을 반환
}