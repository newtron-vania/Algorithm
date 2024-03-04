#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> p;

vector<p> v[1024][1001];
vector<int> trap;

struct point 
{
    int cur, sumcost, state;
    friend bool operator<(const point& a, const point& b) 
    {
        return a.sumcost > b.sumcost;
    }
};
 
int dijkstrak(int start,int end,int n,int statesize) 
{
    vector<vector<int>> dist(1 << statesize, vector<int>(n + 1, 1e8));
    priority_queue<point> pq;
    
    dist[0][start] = 0;
    pq.push({ start,0,0 });
    
    while (!pq.empty()) 
    {
        int cur = pq.top().cur;
        int sumcost = pq.top().sumcost;
        int state = pq.top().state;
        pq.pop();
        
        // 현재 내가 트랩이라면 그 비트를 키거나 꺼줘야함
        if (trap[cur] != -1) 
        {
            state ^= (1 << trap[cur]);
        }
        for (int i = 0; i < v[state][cur].size(); i++) 
        {
            int next = v[state][cur][i].first;
            int cost = v[state][cur][i].second+sumcost;
            if (dist[state][next] > cost) 
            {
                dist[state][next] = cost;
                pq.push({ next,cost,state });
            }
        }
    }
    int res = 1e8;
    for (int i = 0; i < dist.size(); i++)
        res = min(res, dist[i][end]);
    return res;
}

int solution(int n, int start, int end, vector<vector<int>> roads, vector<int> traps) {
    int answer = 0;
    trap = vector<int>(n + 1,-1);
    
    sort(traps.begin(), traps.end());
    
    for (int i = 0; i < traps.size(); i++) 
    {
        trap[traps[i]] = i;
    }
    //트랩을 밟아서 만들수있는 모든 경우의수
    for (int state = 0; state < (1 << traps.size()); state++) 
    {
        for (auto &r : roads) 
        {
            int a = r[0];
            int b = r[1];
            int c = r[2];
            //두노드중 하나라도 트랩인경우
            if ((trap[a] != -1 || trap[b] != -1)) 
            {
                int left = (state & (1 << trap[a])) ? 1 : 0;
                int right = (state & (1 << trap[b])) ? 1 : 0;
                //하나만 트랩일때만 swap
                if (left^right)
                    swap(a, b);
            }
            v[state][a].push_back({ b,c });
        }
    }
    
    return dijkstrak(start,end,n,traps.size());
}