#include <bits/stdc++.h>
using namespace std;

struct TrieNode
{
private:
    TrieNode* children[26] = { nullptr};
    bool isEnd = false;
public:

    void insert(const string& word)
    {
        TrieNode* node = this;
        for (char c : word)
        {
            int idx = c - 'a';
            if (node->children[idx] == nullptr)
            {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }
        node->isEnd = true;
    }

    bool startsWith(const string& prefix)
    {
        TrieNode* node = this;
        for (char c : prefix)
        {
            int idx = c - 'a';
            if (node->children[idx] == nullptr)
            {
                return false;
            }
            node = node->children[idx];
        }
        return true;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    TrieNode* root = new TrieNode();

    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        root->insert(s);
    }

    int count = 0;

    for (int i = 0; i < m; ++i)
    {
        string query;
        cin >> query;
        if (root->startsWith(query))
        {
            count++;
        }
    }

    cout << count << '\n';

    return 0;
}
