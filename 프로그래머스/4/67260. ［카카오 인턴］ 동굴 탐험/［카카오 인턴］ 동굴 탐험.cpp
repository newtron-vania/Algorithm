#include <string>
#include <vector>
#include <queue>
#include <set>
using namespace std;
const int MAX = 200000; // 2e5

vector<int> edge[MAX];
set<int> s;
int key[MAX], needKey[MAX];
bool check_visit[MAX];

void BFS(int node){
    queue<int> q;
    q.push(node);
    check_visit[node] = true;
    
    if(needKey[0] != 0) return; 
    
    while(!q.empty())
    {
        int tmp = q.front();
        q.pop();
        needKey[key[tmp]] = 0;
        
        if(s.find(key[tmp]) != s.end())
        { 
            s.erase(key[tmp]); 
            q.push(key[tmp]); 
            check_visit[key[tmp]] = true;
        }
        for(int it : edge[tmp])
        {
            if(check_visit[it]) continue; 
            if(needKey[it] != 0)
            { 
                s.insert(it);
                continue;
            }
            check_visit[it] = true;
            q.push(it);
        }
    }
}

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
    for(auto &it : path)
    {
        edge[it[0]].push_back(it[1]);
        edge[it[1]].push_back(it[0]);
    }

    for(auto & it : order)
    {
        key[it[0]] = it[1];
        needKey[it[1]] = it[0]; 
    }
    
    BFS(0);
    for(int i = 0 ; i < n ; i++) if(!check_visit[i]) return false;
    return true;
}