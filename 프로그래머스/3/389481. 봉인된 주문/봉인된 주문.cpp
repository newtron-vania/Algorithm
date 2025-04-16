#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 12;

long long power26[MAX];

vector<long long> bannedSpells[MAX];

void init()
{
    power26[0] = 1;
    
    for (int len = 1; len < MAX; len++)
    {
        power26[len] = power26[len - 1] * 26;
    }
}

long long stringToNum(string s) 
{
    long long num = 0;
    
    for (char c : s) 
    {
        num = num * 26 + (c - 'a');
    }
    
    return num;
}

string numToString(long long num, int len) 
{
    string s(len, 'a');
    
    for (int i = len - 1; i >= 0; i--) 
    {
        s[i] = char('a' + (num % 26));
        
        num /= 26;
    }
    
    return s;
}

string solution(long long n, vector<string> bans) {
    init();
    
    for (string ban : bans) 
    {
        int len = ban.size();
        long long num = stringToNum(ban);
        
        bannedSpells[len].push_back(num);
    }
    
    for (int len = 1; len < MAX; len++)
    {
        sort(bannedSpells[len].begin(), bannedSpells[len].end());
    }
    
    for (int len = 1; len < MAX; len++)
    {
        long long totalStrings = power26[len];
        long long bannedCnt = bannedSpells[len].size();
        long long validCnt = totalStrings - bannedCnt;
        
        if (n > validCnt) 
        {
            n -= validCnt;
            
            continue;
        }
        
        // 길이 len 내에서 n번째 유효 주문 탐색
        long long k = n; 
        long long prev = -1;
        long long candidate = -1;
        
        for (long long bannedNum : bannedSpells[len])
        {
            long long gap = bannedNum - (prev + 1);
            
            // k번째 주문은 gap 안에 있으므로, (prev + k)가 그 숫자값
            if (k <= gap) 
            {
                candidate = prev + k;
                
                break;
            }
            
            k -= gap;
            prev = bannedNum;
        }
        
        if (candidate == -1)
        {
            candidate = prev + k;
        }
        
        return numToString(candidate, len);
    }

    return "";
}