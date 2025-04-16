#include <bits/stdc++.h>
using namespace std;

const int ALPHA_COUNT = 26;
char alpha[ALPHA_COUNT];

bool alphaSort(string a, string b)
{
    if(a.size() != b.size()) return a.size() < b.size();
    return a < b;
}

void InitAlpha() {
    for (int i = 0; i < ALPHA_COUNT; i++) 
    {
        alpha[i] = 'a' + i;
    }
}

long long WordToNum(string word)
{
    long long result = 0;
    for (int i = 0; i < word.size(); i++) 
    {
        int idx = (word[i] - 'a') + 1;
        result = result * ALPHA_COUNT + idx;
    }
    return result;
}

string NumToWord(long long num) 
{
    string result = "";

    while (num > 0) 
    {
        num--;
        int index = num % ALPHA_COUNT;
        result = alpha[index] + result;
        num /= ALPHA_COUNT;
    }
    return result;
}

string solution(long long n, vector<string> bans) 
{
    InitAlpha();

    vector<long long> bansToNum;
    for(string ban : bans)
    {
        bansToNum.push_back(WordToNum(ban));
    }
    
    sort(bansToNum.begin(), bansToNum.end());

    int bansLength = bans.size();
    for (int i = bansLength - 1; i >= 0; i--) 
    {
        long long banNum = bansToNum[i];
        if (banNum - i <= n) 
        {
            n += i + 1;
            break;
        }
    }
    
    return NumToWord(n);
}