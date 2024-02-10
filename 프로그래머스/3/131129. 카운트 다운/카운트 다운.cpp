#include <string>
#include <vector>
using namespace std;

// 현재 점수에서 다트를 맞춘점수를 뺀 nextScore에 대한 판별
bool isAbleScore(int nextScore, int cur, vector<pair<int, int>> *cnts) {
    // 1. 버스트
    if (nextScore < 0) return false ;
    // 2. 다트 횟수가 같거나 더많으면
    if ((*cnts)[nextScore].first && (*cnts)[nextScore].first <= (*cnts)[cur].first) return false ;
    // 3. 다트횟수가 하나 적지만 싱글과 불을 맞춘 횟수가 적다면
    if ((*cnts)[nextScore].first == (*cnts)[cur].first + 1 && (*cnts)[nextScore].second > (*cnts)[cur].second) return false ;
    return true;
}

vector<int> solution(int target) 
{
    vector<pair<int, int>> cnts(target+1, {0,0});
    for (int cur=target; cur>0; cur--) 
    {
        int nextScore;
        for (int score=1; score<=20; score++) 
        {
            for (int i=1; i<=3; i++) 
            {
                nextScore = cur - score*i;
                if (!isAbleScore(nextScore, cur, &cnts)) continue ;
                cnts[nextScore].first = cnts[cur].first + 1;
                if (i == 1) cnts[nextScore].second = cnts[cur].second + 1;
                else cnts[nextScore].second = cnts[cur].second;
            }
        }
        nextScore = cur - 50;
        if (!isAbleScore(nextScore, cur, &cnts)) continue ;
        
        cnts[nextScore].first = cnts[cur].first + 1;
        cnts[nextScore].second = cnts[cur].second + 1;
    }
    return {cnts[0].first, cnts[0].second};
}