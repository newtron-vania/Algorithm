#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Node : x, y, value
//좌측 노드와 우측 노드 저장
class Node {
public:
    int x, y, index;
    Node* left;
    Node* right;

    //생성자
    Node(int _x, int _y, int _index) : x(_x), y(_y), index(_index), left(NULL), right(NULL) {}
};

bool compare(const Node& a, const Node& b) {
    if (a.y == b.y) {
        return a.x < b.x;
    }
    return a.y > b.y;
}

//전위 순회 중 -> 좌 -> 우
void preorder(Node* node, vector<int>& result) {
    if (node == NULL) return;
    result.push_back(node->index);
    preorder(node->left, result);
    preorder(node->right, result);
}
//후위 순회 좌 -> 우 -> 중
void postorder(Node* node, vector<int>& result) {
    if (node == NULL) return;
    postorder(node->left, result);
    postorder(node->right, result);
    result.push_back(node->index);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer(2);
    vector<Node> nodes;

    //Node 생성
    for (int i = 0; i < nodeinfo.size(); i++) {
        nodes.push_back(Node(nodeinfo[i][0], nodeinfo[i][1], i + 1));
    }

    sort(nodes.begin(), nodes.end(), compare);

    Node* root = &nodes[0];

    for (int i = 1; i < nodes.size(); i++) {
        Node* current = root;
        while (true) {
            if (nodes[i].x < current->x) {
                if (current->left == NULL) {
                    current->left = &nodes[i];
                    break;
                }
                current = current->left;
            } else {
                if (current->right == NULL) {
                    current->right = &nodes[i];
                    break;
                }
                current = current->right;
            }
        }
    }

    vector<int> preorderResult;
    vector<int> postorderResult;

    preorder(root, preorderResult);
    postorder(root, postorderResult);

    answer[0] = preorderResult;
    answer[1] = postorderResult;

    return answer;
}