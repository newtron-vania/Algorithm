#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct ExploreResult {
    int oddNode = 0;
    int evenNode = 0;
    int reverseOddNode = 0;
    int reverseEvenNode = 0;

    int getOddEvenTree() {
        return (oddNode == 1 && evenNode == 0) || (oddNode == 0 && evenNode == 1) ? 1 : 0;
    }

    int getReverseOddEvenTree() {
        return (reverseOddNode == 1 && reverseEvenNode == 0) || (reverseOddNode == 0 && reverseEvenNode == 1) ? 1 : 0;
    }
};

void exploreTree(unordered_map<int, vector<int>>& tree,unordered_set<int>& visited,ExploreResult& result,int current) 
{
    auto& nexts = tree[current];

    if (nexts.size() % 2 == 0 && current % 2 == 0) result.evenNode++;
    if (nexts.size() % 2 == 1 && current % 2 == 0) result.reverseEvenNode++;
    if (nexts.size() % 2 == 0 && current % 2 == 1) result.reverseOddNode++;
    if (nexts.size() % 2 == 1 && current % 2 == 1) result.oddNode++;

    visited.insert(current);

    for (int next : nexts) {
        if (visited.count(next)) continue;
        exploreTree(tree, visited, result, next);
    }
}

unordered_map<int, vector<int>> initTree(const vector<int>& nodes, const vector<vector<int>>& edges) {
    unordered_map<int, vector<int>> tree;

    for (int node : nodes) {
        tree[node] = {};
    }

    for (const auto& edge : edges) {
        tree[edge[0]].push_back(edge[1]);
        tree[edge[1]].push_back(edge[0]);
    }

    return tree;
}

vector<int> solution(vector<int> nodes, vector<vector<int>> edges) {
    vector<int> answer(2, 0);
    auto tree = initTree(nodes, edges);

    unordered_set<int> visited;

    for (const auto& [key, _] : tree) {
        if (visited.count(key)) continue;

        ExploreResult result;
        exploreTree(tree, visited, result, key);
        answer[0] += result.getOddEvenTree();
        answer[1] += result.getReverseOddEvenTree();
    }

    return answer;
}
