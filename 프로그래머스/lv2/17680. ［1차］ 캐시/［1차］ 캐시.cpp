#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

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

    void ShowNodes() {
        Node* tmp = head;
        while (tmp != NULL) {
            cout << tmp->city << " ";
            tmp = tmp->nextNode;
        }
        cout << endl;
    }

    ~LinkedList() {
        while (head != NULL) {
            Node* tmp = head;
            head = head->nextNode;
            delete tmp;
        }
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