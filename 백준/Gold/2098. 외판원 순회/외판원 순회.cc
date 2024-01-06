#include <iostream>
#include <string.h>
#include <algorithm>


using namespace std;

const int INF = 987654321;
const int MAX = 16;

int N;
int W[MAX][MAX];
int dp[MAX][1<<MAX];   //1<<16 = 2^16개의 노드의 방문 여부를 비트로 표시.
int allVisitBit;

int DFStravel(int cur_node, int visited_bit){   //cur_node : 현재 위치 , visited_bit : 현재 위치를 포함해서 방문했던 곳들 비트로 표현

    if(visited_bit == allVisitBit){             //다 돌았는데
        if(W[cur_node][0]==0) return INF;   //현재 위치에서 첫 시작 노드(0번)로 돌아갈 수 없으면
        else return W[cur_node][0];         //다 돌고 첫 시작노드로 돌아갈 수 있으면??
    }

    //-1이 아니라면 자명한 최소값(dpCost[][]) 바로 리턴.
    if(dp[cur_node][visited_bit] != -1 ) return dp[cur_node][visited_bit];

    //-1이라면
    dp[cur_node][visited_bit] = INF;
    for(int i = 0; i<N; i++){

        if(W[cur_node][i] == 0) continue;   //연결 안 되어 있어서 길이 없거나
        if((visited_bit) & (1<<i)) continue;    //이미 방문한 곳이면

        //DFStravel(i, visited_bit|1<<i) : 현재 노드에서 재귀적으로 다음 노드 방문.
        dp[cur_node][visited_bit] = min(dp[cur_node][visited_bit],
                                            W[cur_node][i] + DFStravel(i, visited_bit|1<<i));
    }
    return dp[cur_node][visited_bit];
}



int main(){

    cin >> N;

    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            cin >> W[i][j];
        }
    }

    allVisitBit = (1<<N) - 1;       //N개 노드 모두 다 방문한 경우 (111...11)
    memset(dp, -1, sizeof(dp));

    int ans = DFStravel(0,1); //0 : 0번 노드가 첫 시작노드 / 1 : 1은 2^0 -> 즉 시작 노드인 0번 노드를 방문했음을 표시)
    //어떤 도시에서 출발하던 비용은 같으므로 0번 노드를 첫 시작노드로 임의 설정.

    cout << ans;

    return 0;
}