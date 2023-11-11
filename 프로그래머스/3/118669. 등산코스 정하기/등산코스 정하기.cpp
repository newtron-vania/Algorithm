#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <iostream>

const int MAX = 50001;
using namespace std;
bool isGate[MAX];
bool isSummit[MAX];
int dist[MAX];

/**
1. 출입구와 목적지가 정해져있다.
2. intesity가 최소, 즉, 가중치를 최소로 하는 경로를 찾는다.
=> 다익스트라 알고리즘

올라갈 때 가중치가 제일 낮으면 내려갈 때도 해당 경로를 똑같이 사용하면 된다 -> 올라가는 것과 내려가는 것을 따로 계산할 필요 X

출입구부터 시작해서 갈 수 있는 경로 중 발견된 경로 중 가장 작은 가중치를 가지고 목적지까지 도달 -> 우선순위 큐 사용
출입구 어디서부터 시작하든 해당 목적지에 도착했을 때 가중치가 더 큰 것이 존재하면 굳이 해당 출입구부터 시작한 경우를 저장할 필요가 없음
-> 공통된 최소 거리 저장 배열을 사용
**/

//다익스트라 알고리즘
vector<int> Dijkstra(vector<pair<int, int>> graph[MAX], int n, vector<int> &gates) {
    vector<vector<int>> result;
    //가중치, 코스 번호로 우선순위 결정
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

    
    fill_n(dist, MAX, -1);
    //출입구 간 이동 제거 및 큐에 삽입
    for (int gate : gates) {
        isGate[gate] = true;
        pq.push({ 0, gate });
    }

    int w, k;
    while (!pq.empty()) {
        w = pq.top()[0];
        k = pq.top()[1];
        pq.pop();
        //꼭대기에 도착한 경우 결과를 저장
        if (isSummit[k]) {
            result.push_back({ w, k });
            continue;
        }

        for (pair<int, int> node : graph[k]) {
            //출입구면 제외
            if (isGate[node.first])
                continue;
            int wt = max(w, node.second);
            //가중치 갱신이 안됐거나 더 낮은 가중치라면 갱신
            if (dist[node.first] == -1 || wt < dist[node.first]) {
                dist[node.first] = wt;
                pq.push({ wt, node.first });
            }
        }
    }
    //가중치, 산봉우리 번호 오름차순으로 정렬
    sort(result.begin(), result.end());
    reverse(result[0].begin(), result[0].end());
    return result[0];
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer = { n, 987654321 };
    //경로 저장용 벡터
    vector<pair<int, int>> graph[MAX];
    
    int x, y, w;
    for (vector<int> path : paths) {
        x = path[0], y = path[1], w = path[2];
        graph[x].push_back(make_pair(y, w));
        graph[y].push_back(make_pair(x, w));
    }

    //꼭대기인 곳을 저장
    for (int summit : summits) {
        isSummit[summit] = true;
    }

    answer = Dijkstra(graph, n, gates);


    return answer;
}