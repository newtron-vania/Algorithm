#include <string>
#include <vector>
#include <map>

#define MIN(a,b)(((a)<(b))?(a):(b))

using namespace std;
map<string, int> fatigues;

int res = 9999;

void dfs(vector<int> picks, vector<string> minerals, int currentPick, int answer = 0) {

    // 곡괭이 다 쓴 경우
    if (!picks[0] && !picks[1] && !picks[2]) res = MIN(res, answer);
    // 광물 다 캔 경우
    if (minerals.size() == 0) res = MIN(res, answer);
    // 만약 곡괭이 수 없는경우 리턴
    if (!picks[currentPick]) return;


    picks[currentPick]--; // 곡괭이 수 마이너스

    // 한 곡괭이로 최대로 캘 수 있는 광물수
    int maxCnt = 5;
    if (minerals.size() < 5) maxCnt = minerals.size();

    // 피로도 체크
    for (int i = 0;i < maxCnt;i++) {
        answer += fatigues[to_string(currentPick) + minerals[i][0]];
    }

    minerals.erase(minerals.begin(), minerals.begin() + maxCnt);

    // 다시 dfs 돌리기
    dfs(picks, minerals, 0, answer);
    dfs(picks, minerals, 1, answer);
    dfs(picks, minerals, 2, answer);
}

int solution(vector<int> picks, vector<string> minerals) {

    //곡괭이 경우의 수 저장
    fatigues["0d"] = 1;
    fatigues["0i"] = 1;
    fatigues["0s"] = 1;
    fatigues["1d"] = 5;
    fatigues["1i"] = 1;
    fatigues["1s"] = 1;
    fatigues["2d"] = 25;
    fatigues["2i"] = 5;
    fatigues["2s"] = 1;

    dfs(picks, minerals, 0);
    dfs(picks, minerals, 1);
    dfs(picks, minerals, 2);

    return res;
}