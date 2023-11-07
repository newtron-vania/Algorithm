#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

//LRU : 가장 최근에 사용한 순서대로 우선순위가 높은 알고리즘
//데이터의 삽입과 삭제가 자유로워야 한다 : LinkedList

//Node
/**
데이터와 앞뒤 노드 데이터를 저장.
해당 노드가 제거될 시 앞 노드와 뒤 노드를 연결한다.
**/
class Node {
public:
    string city;
    Node* nextNode = NULL;
    Node* prevNode = NULL;
};

class LinkedList {
public:
    Node* head = NULL;
    Node* tail = NULL;
    int size = 0;
    //노드 추가
    void AddNodeToFront(const string& _city) {
        size += 1;
        Node* newNode = new Node;
        newNode->city = _city;
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            head->prevNode = newNode;
            newNode->nextNode = head;
            head = newNode;
        }
    }
    //노드 탐색
    //노드가 없다면 새로운 노드를 추가
    //노드가 없는데 캐시가 꽉 찾다면 우선순위가 가장 낮은 노드(tail)을 제거 후 새로운 노드를 추가
    //노드가 있다면 해당 노드를 제거하고 노드를 추가
    Node* SearchNode(const string& city) {
        Node* tmp = head;
        while (tmp != NULL) {
            if (tmp->city == city) {
                return tmp;
            }
            tmp = tmp->nextNode;
        }
        return NULL;
    }

    //노드 제거
    //노드 제거 후 앞 뒤 노드를 연결한다.
    void RemoveNode(Node* searchedNode) {
        size -= 1;
        if (head == searchedNode) {
            head = searchedNode->nextNode;
        }
        if (tail == searchedNode) {
            tail = searchedNode->prevNode;
        }
        if (searchedNode->prevNode != NULL)
            searchedNode->prevNode->nextNode = searchedNode->nextNode;
        if (searchedNode->nextNode != NULL)
            searchedNode->nextNode->prevNode = searchedNode->prevNode;

        delete searchedNode;
    }
};

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    LinkedList cache;
    for (string& city : cities) {
        transform(city.begin(), city.end(), city.begin(), ::tolower);

        Node* cacheNode = cache.SearchNode(city);

        if (cacheNode == NULL) {
            answer += 5;
            if (cache.size < cacheSize) {
                cache.AddNodeToFront(city);
            }
            else if (cache.size == cacheSize && cacheSize > 0) {
                cache.RemoveNode(cache.tail);
                cache.AddNodeToFront(city);
            }
        }
        else {
            answer += 1;
            cache.RemoveNode(cacheNode);
            cache.AddNodeToFront(city);
        }
    }
    return answer;
}