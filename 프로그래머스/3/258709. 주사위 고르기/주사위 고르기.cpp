#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 전역 변수 선언
int targetDiceNum;                       // 게임에 사용할 주사위 수
vector<vector<int>> realDice;            // 각 주사위의 면에 적힌 숫자들을 담는 2차원 벡터
vector<int> DiceListA;                   // 플레이어 A가 만들 수 있는 모든 주사위 조합의 합
vector<int> DiceListB;                   // 플레이어 B가 만들 수 있는 모든 주사위 조합의 합
int maxWinNum;                           // 최대 승리 횟수
vector<int> winA;                        // 승리 시 A의 주사위 조합

void makeList(vector<int> DL, bool isA, int deep, int Num) //주사위 조합 구하기
{
    if (deep == DL.size())
    {
        if (isA)
        {
            DiceListA.push_back(Num);
        }
        else
        {
            DiceListB.push_back(Num);
        }
        return;    
    }
    else
    {
        for (int i = 0; i < 6; i++)
        {
            makeList(DL, isA, deep + 1, Num + realDice[DL[deep]][i]);
        }
    }
}

// A와 B의 주사위 조합들을 계산하고 비교하여 승리 횟수를 계산하는 함수
void calc(vector<int> AD, vector<int> BD)
{
    DiceListA = vector<int>(0);
    DiceListB = vector<int>(0);
    makeList(AD, true, 0, 0);  // A의 주사위 조합 생성
    makeList(BD, false, 0, 0); // B의 주사위 조합 생성
    sort(DiceListA.begin(), DiceListA.end());
    sort(DiceListB.begin(), DiceListB.end());

    int aIdx = 0, bIdx = 0;
    int winNum = 0;
    while (aIdx < DiceListA.size() && bIdx < DiceListB.size())
    {
        if (DiceListA[aIdx] > DiceListB[bIdx])
        {
            bIdx += 1;
        }
        else
        {
            winNum += bIdx;
            aIdx += 1;
        }
    }

    if (bIdx == DiceListB.size())
    {
        winNum += bIdx * (DiceListA.size() - aIdx);
    }
    if (winNum > maxWinNum)
    {
        maxWinNum = winNum;
        winA = AD;
    }
}

// 가능한 모든 주사위 조합을 만들기 위해 조합(combination)을 계산하는 함수
void combi(vector<int> AD, vector<int> BD, int nowD)
{
    vector<int> tD;
    if (AD.size() == targetDiceNum)
    {
        tD = BD;
        for (int i = nowD; i < realDice.size(); i++)
        {
            tD.push_back(i);
        }
        calc(AD, tD);
    }
    else if (BD.size() == targetDiceNum)
    {
        tD = AD;
        for (int i = nowD; i < realDice.size(); i++)
        {
            tD.push_back(i);
        }
        calc(tD, BD);
    }
    else
    {
        tD = AD;
        tD.push_back(nowD);
        combi(tD, BD, nowD + 1);
        tD = BD;
        tD.push_back(nowD);
        combi(AD, tD, nowD + 1);
    }
    return;
}

// 이 함수는 메인 알고리즘을 실행하는 솔루션 함수입니다.
vector<int> solution(vector<vector<int>> dice)
{
    realDice = dice;
    targetDiceNum = dice.size() / 2;
    combi(vector<int>(0), vector<int>(0), 0);
    for (int i = 0; i < winA.size(); i++)
    {
        winA[i] += 1;
    }
    return winA;
}
