#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
private:
    TrieNode* children[26] = { nullptr };
    int count = 0;

public:
    TrieNode() {}

    void insert(const string& word)
    {
        TrieNode* node = this;
        for (char c : word)
        {
            node->count++;
            int idx = c - 'a';
            if (!node->children[idx])
            {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }
    }

    int search(const string& pattern)
    {
        TrieNode* node = this;
        for (char c : pattern)
        {
            if (c == '?') return node->count;

            int idx = c - 'a';
            if (!node->children[idx]) return 0;
            node = node->children[idx];
        }
        return 0;
    }
};

TrieNode forwardTrie[10001];
TrieNode reverseTrie[10001];

vector<int> solution(vector<string> words, vector<string> queries)
{
    vector<int> answer;

    for (const string& word : words)
    {
        int len = word.length();
        forwardTrie[len].insert(word);

        string rev = word;
        reverse(rev.begin(), rev.end());
        reverseTrie[len].insert(rev);
    }

    for (const string& q : queries)
    {
        int len = q.length();
        if (q[0] != '?')
        {
            answer.push_back(forwardTrie[len].search(q));
        }
        else
        {
            string revQuery = q;
            reverse(revQuery.begin(), revQuery.end());
            answer.push_back(reverseTrie[len].search(revQuery));
        }
    }

    return answer;
}
