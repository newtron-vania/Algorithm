#include <string>
#include <vector>
#include <queue>

using namespace std;
vector<vector<int>> tree;
vector<bool> visited;
int retAns=0;

void DFS(int nowNode, int parNode)
{
    for (int i = 0; i < tree[nowNode].size(); i++)
    {
        if (tree[nowNode][i] != parNode)
        {
            DFS(tree[nowNode][i], nowNode);
            if (!visited[nowNode] && !visited[tree[nowNode][i]])
            {
                visited[nowNode] = true;
                retAns += 1;
            }
        }        
    }    
}

int solution(int n, vector<vector<int>> lighthouse) 
{
    tree=vector<vector<int>>(n+1);
    visited=vector<bool>(n + 1,false);
    vector<int> parents(n + 1, 0);
    for (int i = 0; i < lighthouse.size(); i++){
        tree[lighthouse[i][0]].push_back(lighthouse[i][1]);
        tree[lighthouse[i][1]].push_back(lighthouse[i][0]);
    }
    DFS(1,1);
    return retAns;
}