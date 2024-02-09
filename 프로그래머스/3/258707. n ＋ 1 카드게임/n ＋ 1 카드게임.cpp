#include <bits/stdc++.h>
#include <string>
#include <vector>

using namespace std;

int n;
int coinCount;
queue<int> player;
vector<int> checkNum;
queue<int> nextCard;
pair<int, int> p;

bool checkCard(int checkNumber)
{
    
    int qSize = player.size();
    for(int i = 0; i < qSize; i++)  //현재 카드로 n+1수를 만들 수 있는지 확인
    {
        int num = player.front();   player.pop();
        if(checkNum[num] == 0)  //이미 사용한 카드거나 없다면
            continue;
        
        if(checkNum[(n+1)-num] != 0){   //카드 중에 n+1을 만들 수 있는 카드가 있다면
            if(checkNumber == 0)    //코인 0개를 사용하는 경우
            {
                if(checkNum[(n+1)-num] != 1 || checkNum[num] != 1)  //두 카드가 플레이어가 들고 있는 카드일 경우
                {
                    player.push(num);
                    continue;
                }

                p = make_pair(checkNum[num], checkNum[(n+1)-num]);
                checkNum[num] = 0;
                checkNum[(n+1)-num] = 0;
                return true;
            }else if(checkNumber == 1)    //코인 1개를 사용하는 경우
            {
                if(checkNum[(n+1)-num] == 1 && checkNum[num] == 2 && coinCount >= 1 ||
                   checkNum[(n+1)-num] == 2 && checkNum[num] == 1 && coinCount >= 1)    //두 카드 중 한개만 뽑을 카드일 경우
                {
                    coinCount -= 1;
                    p = make_pair(checkNum[num], checkNum[(n+1)-num]);
                    checkNum[num] = 0;
                    checkNum[(n+1)-num] = 0;
                    return true;
                }
            }else if(checkNumber == 2)    //코인 2개를 사용하는 경우
            {
                if(checkNum[(n+1)-num] == 2 && checkNum[num] == 2 && coinCount >= 2)    //두 카드 모두 뽑을 카드일 경우
                {
                    coinCount -= 2;
                    p = make_pair(checkNum[num], checkNum[(n+1)-num]);
                    checkNum[num] = 0;
                    checkNum[(n+1)-num] = 0;
                    return true;
                }
               
            }
        }
        player.push(num);
    }
    
    return false;
}

int solution(int coin, vector<int> cards) {
    int answer = 0;
    n = cards.size();
    checkNum.assign(1001, 0);
    int index = n/3;
    coinCount = coin;
    
    //처음에 들고 갈 카드 저장
    for(int i = 0; i < n/3; i++)
    {
        player.push(cards[i]);
        checkNum[cards[i]] = 1;
    }
    
    while(true) //3가지의 경우가 불가능할때까지 반복
    {
        answer++;
        if(index >= cards.size()-1) //뽑을 카드가 없다면 끝
            break;
        
        bool isComplete = false;
        checkNum[cards[index]] = 2;
        checkNum[cards[index+1]] = 2;
        player.push(cards[index]);
        player.push(cards[index+1]);
        index += 2;
        
        isComplete = checkCard(0);
        if(isComplete) //현재 있는 카드로 체크
            continue;
        
        if(coinCount > 0)
        {
            isComplete = checkCard(1);  //코인 한 개를 사용하여 n+1을 만들 수 있는지 확인
            if(isComplete)
                continue;
            
            isComplete = checkCard(2);  //코인 두 개를 사용하여 n+1을 만들 수 있는지 확인
            if(isComplete)
                continue;
        }
        if(!isComplete)
            break;
    }
    
    return answer;
}