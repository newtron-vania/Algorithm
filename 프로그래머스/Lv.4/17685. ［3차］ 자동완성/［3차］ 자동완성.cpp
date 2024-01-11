#include <string>
#include <vector>
 
using namespace std;
 
struct TRIE
{
    TRIE *Node[26];
    int child;
    bool finish;
 
    void Insert(const char *str);
    int Find(const char *str, int cnt);
};
 
int trie_Idx;
TRIE nodepool[1000010];
 
TRIE *Nodeset()
{
    TRIE *newNode = &nodepool[trie_Idx++];
    for (int i = 0; i < 26; i++) newNode->Node[i] = NULL;
    newNode->child = 0;
 
    return newNode;
}
 
void TRIE::Insert(const char *str)
{
    child++;
    if (*str == NULL)
    {
        finish = true;
        return;
    }
 
    int cur = *str - 'a';
    if (Node[cur] == NULL) Node[cur] = Nodeset();
    Node[cur]->Insert(str + 1);
}
 
int TRIE::Find(const char *str, int cnt)
{
    if (child == 1 || *str == NULL) return cnt;
 
    int cur = *str - 'a';
    return Node[cur]->Find(str + 1, cnt + 1);
}
 
int solution(vector<string> words) 
{
    trie_Idx = 0;
    int answer = 0;
    int N = words.size();
    TRIE *root = Nodeset();
    for (int i = 0; i < N; i++) root->Insert(words[i].c_str());
    for (int i = 0; i < N; i++) answer = answer + root->Find(words[i].c_str(), 0);
    
    return answer;
}