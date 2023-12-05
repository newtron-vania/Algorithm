#include <string>
#include <vector>
#include <queue>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node(int _val) {
        val = _val;
    }
};

int solution(int n, vector<vector<int>> edge) {
    int answer = -1;

    vector<Node*> graph(n + 1, nullptr);
    vector<bool> visited(n + 1, false);

    //새 노드들을 생성
    for (int i = 1; i <= n; ++i) {
        graph[i] = new Node(i);
    }

     //edge를 통해 노드간 연결을 확인
    for (vector<int> e : edge) {
        int from = e[0];
        int to = e[1];
        graph[from]->neighbors.push_back(graph[to]);
        graph[to]->neighbors.push_back(graph[from]);
    }

    queue<Node*> q;
    q.push(graph[1]);
    visited[1] = true;
    
    //같은 길이의 노드들의 다음 노드들을 참조하고 방문했던 노드가 아니라면 다음 해당 노드를 저장하고, 같은 길이의 노드 개수를 answer에 저장한다.
    while (!q.empty()) {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; ++i) {
            Node* curr = q.front();
            q.pop();

            for (Node* neighbor : curr->neighbors) {
                if (!visited[neighbor->val]) {
                    visited[neighbor->val] = true;
                    q.push(neighbor);
                }
            }
        }
        answer = levelSize;
    }

    //메모리 해제
    for (int i = 1; i <= n; ++i) {
        delete graph[i];
    }

    return answer;
}
