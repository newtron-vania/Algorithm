#include <bits/stdc++.h>

using namespace std;

struct TrieNode 
{
    int count = 0;
    TrieNode* next[26] = {nullptr};

    void insert(const string& s)
    {
        TrieNode* node = this;
        for (char c : s) 
        {
            int idx = c - 'a';
            if (!node->next[idx]) 
            {
                node->next[idx] = new TrieNode();
            }
            node = node->next[idx];
        }
        node->count++;
    }

    int find(const string& s)
    {
        TrieNode* node = this;
        for (char c : s) 
        {
            int idx = c - 'a';
            if (!node->next[idx]) return 0;
            node = node->next[idx];
        }
        return node->count;
    }
};

void DFS(int depth, string value, pair<int, int> pos, int max_depth, int n, int m, char graph[10][10], TrieNode& node)
{
    node.insert(value);

    if(depth == max_depth)
    {
        return;
    }
    
    for(int i : {-1, 0, 1})
    {
        for(int j : {-1, 0, 1})
        {
            if(!(i == 0 && j == 0))
            {
                int nx = (pos.first + i + n) % n, ny = (pos.second + j + m) % m;
                DFS(depth + 1, value + graph[nx][ny], pair<int, int>(nx, ny), max_depth, n, m, graph, node);
            }
        }
    }
    
}


int main()
{
    int n, m, k;
    
    scanf("%d %d %d", &n, &m, &k);
    
    char graph[10][10];
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            scanf(" %c", &graph[i][j]);
        }
    }

    // TRIE 사전 만들기
    TrieNode trie;
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            string start(1, graph[i][j]);
            DFS(1, start, pair<int, int>(i, j), 5, n, m, graph, trie);
        }
    }
    
    for(int i = 0; i < k; i++)
    {
        char buf[101]; 
        scanf("%s", buf); 
        string word = buf;
        printf("%d\n", trie.find(word));
    }
}