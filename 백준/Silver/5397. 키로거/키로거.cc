#include <bits/stdc++.h>
using namespace std;

struct Linked
{
    char c;
    Linked* before = nullptr;
    Linked* next = nullptr;

    Linked(char ch = 0)
        : c(ch), before(nullptr), next(nullptr)
    {
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    while (n-- > 0)
    {
        string s;
        cin >> s;

        Linked* head = new Linked();  // 더미 헤드
        Linked* cur = head;           // 커서 위치

        for (char ch : s)
        {
            if (ch == '<')
            {
                if (cur->before != nullptr)
                    cur = cur->before;
            }
            else if (ch == '>')
            {
                if (cur->next != nullptr)
                    cur = cur->next;
            }
            else if (ch == '-')
            {
                if (cur != head)
                {
                    Linked* delNode = cur;

                    // 이전 노드와 다음 노드 연결
                    delNode->before->next = delNode->next;
                    if (delNode->next)
                        delNode->next->before = delNode->before;

                    cur = delNode->before;
                    delete delNode;
                }
            }
            else
            {
                Linked* newNode = new Linked(ch);
                newNode->before = cur;
                newNode->next = cur->next;
                if (cur->next)
                    cur->next->before = newNode;
                cur->next = newNode;
                cur = newNode;
            }
        }

        Linked* p = head->next;
        while (p)
        {
            cout << p->c;
            p = p->next;
        }
        cout << '\n';

        // 메모리 해제
        p = head;
        while (p)
        {
            Linked* temp = p;
            p = p->next;
            delete temp;
        }
    }
}
