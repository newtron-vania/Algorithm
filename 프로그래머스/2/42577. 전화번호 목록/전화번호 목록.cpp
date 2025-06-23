#include <bits/stdc++.h>

using namespace std;

class TrieNode
{
private:
    TrieNode* children[10] = { nullptr };
    int count = 0;
public:
    TrieNode() {}
    
    void insert(const string& numbers)
    {
        TrieNode* node = this;
        for (char c : numbers)
        {
            node->count++;
            int idx = c - '0';
            if (!node->children[idx])
            {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }
    }

    bool search(const string& pattern)
    {
        TrieNode* node = this;
        for (char c : pattern)
        {
            int idx = c - '0';
            if (!node->children[idx]) return false;
            node = node->children[idx];
        }
        
        for(const auto& child : node->children)
        {
            if(child != nullptr) return false;
        }
        
        return true;
    }
};

bool solution(vector<string> phone_book) 
{
    bool answer = true;
    
    TrieNode* TrieTree = new TrieNode();
    for(const auto& number : phone_book)
    {
        TrieTree->insert(number);
    }
    
    for(const auto& number : phone_book)
    {
        if(!TrieTree->search(number))
        {
            answer = false;
            break;
        }
    }
    
    return answer;
}