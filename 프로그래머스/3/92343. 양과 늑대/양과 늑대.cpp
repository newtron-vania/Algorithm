#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Node {
    int sheep; // 모은 양의 수
    int wolf; // 모은 늑대의 수
    int route; // 현재까지 방문한 노드들

    Node(int _sheep, int _wolf, int _route) : sheep(_sheep), wolf(_wolf), route(_route) {}
};

bool visit[132000];

int solution(vector<int> info, vector<vector<int>> edges) {
    int S = info.size();
    vector<vector<int>> g(S);
    for(auto edge: edges) {
        g[edge[0]].push_back(edge[1]);
    }

    queue<Node*> q;
    
    q.push(new Node(1, 0, (1 << 0))); // 루트 노드
    visit[(1<<0)] = true;
    int answer = 1;

    while(!q.empty()) {
        Node *cur = q.front(); q.pop();

        int sheep = cur->sheep;
        int wolf = cur->wolf;
        int route = cur->route;

        for(int i=0; i<S; ++i) 
        {
            // 현재까지 방문한 노드에서
            if(route & (1 << i)) 
            { 
                // 다음으로 이동할 노드
                for(auto next: g[i]) 
                { 
               	    int next_route = route | (1 << next);
                    
                    // 양
                    if(info[next] == 0) 
                    { 
                        if(visit[next_route]) continue; // 만약 똑같이 방문한적이 있다면 pass

                        answer = max(answer, sheep+1);
                        visit[next_route] = true;
                        q.push(new Node(sheep+1, wolf, next_route));
                    }
                    // 늑대
                    else 
                    {
                        if(sheep > wolf+1) 
                        {
                            if(visit[next_route]) continue;

                            visit[next_route] = true;
                            q.push(new Node(sheep, wolf+1, next_route));
                        }
                    }
                }
            }
        }
    }

    return answer;
}