#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;
/**
1. 대실 예약 시간을 오름차순으로 정렬한다.
2. 대실 시작 시간 = stT, 대실 종료 시간 = edT
3. i.stT <= j.stT일 때, i.edT <= j.stT 라면 i와 j는 같은 객실을 사용할 수 있다.
4. 대실 예약 시간을 정렬함으로써 i < j && i.stT < j.stT를 만족한다.
5. 최솟값이 우선순위를 갖는 우선순위 큐를 통해 edT를 push하며, q.top()(가장 작은 edT) <= j.stT면 3을 만족하므로 같은 객실을 사용할 수 있다.
6. 같은 객실을 사용하는 경우 더 작은 시간의 값은 의미가 없으므로 pop한다.
7. 우선순위 큐의 size가 증가한다는 것은 우선순위 큐의 크기만큼의 시간들은 무조건 다른 대실을 사용한다는 의미이다.
8. 우선순위 큐에 삽입 후 우선순위 큐 size위 최댓값을 answer에 저장한다.
**/
int solution(vector<vector<string>> book_time) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> q;
    sort(book_time.begin(), book_time.end());
    for (int i = 0; i < book_time.size(); i++) {
        string st = book_time[i][0];
        string ed = book_time[i][1];
        int stT = stoi(st.substr(0, 2)) * 60 + stoi(st.substr(3));
        int edT = stoi(ed.substr(0, 2)) * 60 + stoi(ed.substr(3)) + 10;
        while (!q.empty() && q.top() <= stT) {
            q.pop();
        }
        
        q.push(edT);
        answer = max(answer, (int)q.size());
    }
    return answer;
}