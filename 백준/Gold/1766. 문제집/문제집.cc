#include <bits/stdc++.h>
using namespace std;


const int MAX = 32001;
int N, M;
int inDegree[MAX];
vector<int> Problem[MAX];

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i = 0; i < M; i++) 
    {
        int a, b;
        cin >> a >> b;
        Problem[a].push_back(b);
        inDegree[b]++;
    }

    priority_queue<int, vector<int>, greater<int>> pq; // 내림차순
    for(int i = 1; i <= N; i++) 
    {
        if(inDegree[i] == 0) 
        {
            pq.push(i);
        }
    }

    vector<int> res;
    for(int i = 1; i <= N; i++)
    {
        if(pq.empty())
        {
            break;
        }
        int node = pq.top();
        pq.pop();
        cout << node << " ";

        for(int i = 0; i < Problem[node].size(); i++)
        {
            int nextNode = Problem[node][i];
            inDegree[nextNode] -= 1;
            if(inDegree[nextNode] == 0)
            {
                pq.push(nextNode);
            }
        }
    }

    return 0;
}