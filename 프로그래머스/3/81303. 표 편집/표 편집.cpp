#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int n;
    Node* prev;
    Node* next;
    Node(int n, Node* prev, Node* next)
        : n(n), prev(prev), next(next) {}
};

void ProcessCommand(Node*& select, stack<Node*>& remove_table, const string& c)
{
    if (c[0] == 'C')
    {
        remove_table.push(select);

        if (select->prev)
            select->prev->next = select->next;

        if (select->next)
            select->next->prev = select->prev;

        Node* nextNode = select->next ? select->next : select->prev;
        select = nextNode;
    }
    else if (c[0] == 'Z')
    {
        Node* restored = remove_table.top();
        remove_table.pop();

        if (restored->prev)
            restored->prev->next = restored;

        if (restored->next)
            restored->next->prev = restored;
    }
    else
    {
        int count = stoi(c.substr(2));

        if (c[0] == 'U')
        {
            for (int i = 0; i < count; i++)
            {
                if (select->prev)
                    select = select->prev;
            }
        }
        else if (c[0] == 'D')
        {
            for (int i = 0; i < count; i++)
            {
                if (select->next)
                    select = select->next;
            }
        }
    }
}

string solution(int n, int k, vector<string> cmd)
{
    string answer(n, 'O');
    stack<Node*> remove_table;

    Node* head = new Node(0, nullptr, nullptr);
    Node* curr = head;

    for (int i = 1; i < n; i++)
    {
        Node* newNode = new Node(i, curr, nullptr);
        curr->next = newNode;
        curr = newNode;
    }

    Node* select = head;
    for (int i = 0; i < k; i++)
    {
        select = select->next;
    }

    for (const auto& c : cmd)
    {
        ProcessCommand(select, remove_table, c);
    }

    while (!remove_table.empty())
    {
        answer[remove_table.top()->n] = 'X';
        remove_table.pop();
    }

    Node* iter = head;
    while (iter)
    {
        Node* next = iter->next;
        delete iter;
        iter = next;
    }

    return answer;
}
