#include <string>
#include <vector>
#include <sstream>
#include <stack>

using namespace std;

struct Node {
    int n;
    Node* prev;
    Node* next;
    Node(int n, Node* prev, Node* next) : n(n), prev(prev), next(next) {}
};

string solution(int n, int k, vector<string> cmd) {
    string answer(n, 'O');
    stack<Node*> remove_table;

    Node* o = new Node(0, NULL, NULL);
    
    Node* select = o;
    
    for (int i = 1; i < n; i++) {
        o->next = new Node(i, o, NULL);
        o = o->next;
    }
    
    for (int i = 0; i < k; i++) { 
        select = select->next;
    }
    
    for (const auto& c : cmd) {
        if (c == "C") {
            remove_table.push(select);
            if (select->prev != NULL) {
                select->prev->next = select->next;
            }

            if (select->next != NULL) {
                select->next->prev = select->prev;
            }

            if (select->next == NULL) {
                select = select->prev;
            }
            else {
                select = select->next;
            }
        }
        else if (c == "Z") {
            Node* t = remove_table.top();
            remove_table.pop();

            if (t->prev != NULL) {
                t->prev->next = t;
            }

            if (t->next != NULL) {
                t->next->prev = t;
            }
        }
        else {
            int count = stoi(c.substr(2));

            if (c[0] == 'D') {
                for (int i = 0; i < count; i++) {
                    select = select->next;
                }
            }
            else {
                for (int i = 0; i < count; i++) {
                    select = select->prev;
                }
            }
        }
    }

    while (!remove_table.empty()) {
        answer[remove_table.top()->n] = 'X';
        remove_table.pop();
    }

    return answer;
}