#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int targetDiceNum;
vector<vector<int>> realDice;
vector<int> DiceListA;
vector<int> DiceListB;
int maxWinNum;
vector<int> winA;

void makeList(vector<int> DL,bool isA, int deep, int Num) //주사위 조합 구하기
{
    if (deep==DL.size())
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
        for (int i=0; i<6; i++)
        {
            makeList(DL, isA, deep+1,Num+realDice[DL[deep]][i]);
        }
    }
}

void calc(vector<int> AD,vector<int> BD)
{
    DiceListA=vector<int>(0);
    DiceListB=vector<int>(0);
    makeList(AD, true, 0, 0);
    makeList(BD, false, 0, 0);
    sort(DiceListA.begin(),DiceListA.end());
    sort(DiceListB.begin(),DiceListB.end());
    int aIdx=0, bIdx=0;
    int winNum=0;
    while (aIdx<DiceListA.size()&&bIdx<DiceListB.size()) //주사위 합 비교
    {
        if (DiceListA[aIdx]>DiceListB[bIdx])
        {
            bIdx+=1;
        }
        else
        {    
            winNum+=bIdx;
            aIdx+=1;
        }
    }    
    if (bIdx==DiceListB.size())
    {
        winNum+=bIdx*(DiceListA.size()-aIdx);
    }
    if (winNum>maxWinNum)
    {
        maxWinNum=winNum;
        winA=AD;
    }
}

void combi(vector<int> AD,vector<int> BD, int nowD)
{
    vector<int> tD;
    if (AD.size()==targetDiceNum)
    {
        tD=BD;
        for (int i=nowD; i<realDice.size(); i++)
        {
            tD.push_back(i);
        }
        calc(AD,tD);
    }
    else if (BD.size()==targetDiceNum)
    {
        tD=AD;
        for (int i=nowD; i<realDice.size(); i++)
        {
            tD.push_back(i);
        }
        calc(tD,BD);
    }
    else
    {
        tD=AD;
        tD.push_back(nowD);
        combi(tD, BD, nowD+1);
        tD=BD;
        tD.push_back(nowD);
        combi(AD, tD, nowD+1);
    }
    return;
}

vector<int> solution(vector<vector<int>> dice) {
    realDice=dice;
    targetDiceNum=dice.size()/2;
    combi(vector<int>(0),vector<int>(0), 0);
    for (int i=0; i<winA.size(); i++)
    {
        winA[i]+=1;
    }
    return winA;
}