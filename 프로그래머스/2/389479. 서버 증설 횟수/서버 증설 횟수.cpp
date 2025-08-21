#include <string>
#include <queue>
#include <vector>

using namespace std;

int solution(vector<int> players, int m, int k) 
{
    int answer = 0;
    // 추가로 필요한 서버들의 남은 시간이 담긴 배열
    queue<int> serverTimes;
    for(int thisTimePlayers : players)
    {
        // 추가로 필요한 서버의 갯수
        int moreServers = thisTimePlayers/m;
        // 새로 추가해야하는 서버의 갯수  = 추가로 필요한 서버의 갯수가 이미 있는 서버보다 클경우 추가로 필요한서버 - 이미 추가한 서버의 갯수. 이미 충족하는경우는 0
        int newServers = moreServers > serverTimes.size() ? moreServers-serverTimes.size() : 0;
        // 서버를 newServers만큼 증설하니 증설갯수 추가
        answer += newServers;
        // 서버당 시간 추가해주기
        while(newServers--)serverTimes.push(k);
        // 현재 큐의 길이 계산
        int n = serverTimes.size();
        // 큐 길이만큼 front(), pop()을 하고 
        for(int i=0; i<n; i++)
        {
            int cur = serverTimes.front(); serverTimes.pop();
            cur--;
            // 서버 사용 가능한 시간이 남아있으면 다시 큐에 넣어주기
            if(cur>0)serverTimes.push(cur);
        }
    }
    return answer;
}