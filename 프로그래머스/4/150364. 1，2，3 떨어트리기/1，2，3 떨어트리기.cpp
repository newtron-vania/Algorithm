#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

unordered_map<int, vector<int>> edge_dict;
unordered_map<int, pair<int, vector<int>>> tree_dict;
vector<bool> visited;
vector<int> order_list;
vector<int> answer;
unordered_map<int, int> leaf_cap_dict;
unordered_map<int, bool> is_leaf_succeeded;

vector<int> dfs(int node) {
    vector<int> child_list;
    for (int child : edge_dict[node]) {
        if (visited[child]) continue;
        visited[child] = true;
        child_list.push_back(child);
    }

    if (child_list.empty()) return {node};

    sort(child_list.begin(), child_list.end());
    tree_dict[node] = {0, child_list};

    vector<int> leaf_list;
    for (int child : child_list) {
        vector<int> child_leaves = dfs(child);
        leaf_list.insert(leaf_list.end(), child_leaves.begin(), child_leaves.end());
    }
    return leaf_list;
}

int search(int node) {
    if (tree_dict.find(node) == tree_dict.end()) return node;

    int idx = tree_dict[node].first;
    tree_dict[node].first = (tree_dict[node].first + 1) % tree_dict[node].second.size();
    return search(tree_dict[node].second[idx]);
}

vector<int> solution(vector<vector<int>> edges, vector<int> target) {
    int n = target.size();
    visited.assign(n, false);
    visited[0] = true;

    for (const auto& edge : edges) {
        int a = edge[0], b = edge[1];
        edge_dict[a-1].push_back(b-1);
        edge_dict[b-1].push_back(a-1);
    }

    vector<int> leaf_list = dfs(0);

    for (int leaf : leaf_list) {
        leaf_cap_dict[leaf] = 0;
        is_leaf_succeeded[leaf] = (target[leaf] == 0);
    }

    while (true) {
        bool all_succeeded = true;
        for (const auto& [leaf, succeeded] : is_leaf_succeeded) {
            if (!succeeded) {
                all_succeeded = false;
                break;
            }
        }
        if (all_succeeded) break;

        int cur_node = search(0);
        leaf_cap_dict[cur_node]++;

        if (leaf_cap_dict[cur_node] > target[cur_node]) return {-1};
        if (!is_leaf_succeeded[cur_node] && leaf_cap_dict[cur_node] * 3 >= target[cur_node]) {
            is_leaf_succeeded[cur_node] = true;
        }

        order_list.push_back(cur_node);
    }

    answer.assign(order_list.size(), 0);
    for (int leaf : leaf_list) {
        vector<int> leaf_result;
        int sur_cap = target[leaf] - leaf_cap_dict[leaf];
        leaf_result.insert(leaf_result.end(), leaf_cap_dict[leaf] - sur_cap % 2 - sur_cap / 2, 1);
        leaf_result.insert(leaf_result.end(), sur_cap % 2, 2);
        leaf_result.insert(leaf_result.end(), sur_cap / 2, 3);

        for (int idx = 0; idx < order_list.size(); idx++) {
            if (order_list[idx] == leaf) {
                answer[idx] = leaf_result[0];
                leaf_result.erase(leaf_result.begin());
            }
        }
    }

    return answer;
}