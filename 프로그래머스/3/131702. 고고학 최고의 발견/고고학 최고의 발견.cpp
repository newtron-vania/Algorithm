#include <string>
#include <vector>
#include <cmath>
using namespace std;

const int MARKER = 1<<20;

int getScore(vector<vector<int>>& clockHands)
{
    const int n = clockHands.size();

    int ret = 0;

    for(int i = 0; i < n - 1; ++i)
    {
        for(int j = 0 ; j < n; ++j)
        {
            if(clockHands[i][j] != 0)
            {
                int tmp  = 4 - clockHands[i][j];

                ret += tmp;

                clockHands[i][j] = (clockHands[i][j] + tmp) % 4;

                clockHands[i+1][j] = (clockHands[i+1][j] + tmp) % 4;

                if(j > 0)
                {
                    clockHands[i+1][j-1] = (clockHands[i+1][j-1] + tmp) % 4;
                }
                if(j + 1 < n)
                {
                    clockHands[i+1][j+1] = (clockHands[i+1][j+1] + tmp) % 4;
                }
                if(i + 2 < n)
                {
                    clockHands[i+2][j] = (clockHands[i+2][j] + tmp) % 4;
                }
            }
        }        
    }

    for(const auto v : clockHands.back())
    {
        if(v != 0)
        {
            ret = MARKER;
            break;
        }
    }

    return ret;
}

int solution(vector<vector<int>> clockHands) {
    int answer = MARKER;

    const int n = clockHands.size();

    int rMax = pow(4,n);
    for(int r = 0; r <rMax; ++r)
    {
        const int i = 0;
        auto clockHandsTmp = clockHands;
        int rTmp = r;
        int tmpSum = 0;
        for(int j = 0; j < n; ++j)
        {
            int tmp = rTmp%4;
            rTmp/=4;
            if(tmp)
            {
                tmpSum += tmp;
                clockHandsTmp[i][j] = (clockHandsTmp[i][j] + tmp) % 4;
                clockHandsTmp[i+1][j] = (clockHandsTmp[i+1][j] + tmp) % 4;
                if(j > 0)
                {
                    clockHandsTmp[i][j-1] = (clockHandsTmp[i][j-1] + tmp) % 4;
                }
                if(j + 1 < n)
                {
                    clockHandsTmp[i][j+1] = (clockHandsTmp[i][j+1] + tmp) % 4;         
                }  
            }
        }

        answer = min(answer,tmpSum + getScore(clockHandsTmp));
    }


    return answer;
}
