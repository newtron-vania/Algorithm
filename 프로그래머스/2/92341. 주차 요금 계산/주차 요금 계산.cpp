#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

vector<string> Split(string str, char delimeter);

vector<int> solution(vector<int> fees, vector<string> records) 
{
    vector<int> answer;
    //기본 시간, 시간 요금, 단위 시간, 단위 요금
    int basicTime = fees[0];
    int basicTex = fees[1];
    int basicTerm = fees[2];
    int basicTermTex = fees[3];
    
    map<string, int> recordDict;
    map<string, int> recordAnswer;
    for(string record : records)
    {
        vector<string> str = Split(record, ' ');
        int time = stoi(str[0].substr(0,2)) * 60 + stoi(str[0].substr(3,2));
        //입차 시간 등록
        if(str[2] == "IN")
        {
            recordDict[str[1]] = time;
        }
        else
        {
            //해당 차량 누적 주차 시간 저장
            recordAnswer[str[1]] += time - recordDict[str[1]];
            //출차 시 입차 시간 초기화
            recordDict[str[1]] = -1;
        }
    }
    //map이라서 key 순으로 자동 정렬
    for(auto& itr : recordDict)
    {
        //입차 시간이 초기화된 상태가 아니라면 == 입차 후 출차한 차량이 아님
        //23:59에 출차된 것으로 간주
        if(itr.second >= 0)
        {
            recordAnswer[itr.first] += 24*60 - 1 - itr.second;
            itr.second = 0;
        }
        //누적 요금 = ((누적 시간 - 기본 시간) / 단위 시간)(소수점이 있으면 +1) * 단위요금
        //만약 누적 시간이 기본 시간보다 적으면 기본 요금만 계산(기본 요금 + (max(0, 누적 요금) * 단위 요금))
        int accumulate_Time = ceil((float)(recordAnswer[itr.first] - basicTime) / basicTerm);
        int texResult = basicTex + (max(0,accumulate_Time) * basicTermTex);
        answer.push_back(texResult);
    }
    return answer;
}
//Split 함수
vector<string> Split(string str, char delimeter)
{
    string tmp;
    vector<string> result;
    istringstream ss(str);
    while(getline(ss, tmp, delimeter))
    {
        result.push_back(tmp);
    }
    return result;
}