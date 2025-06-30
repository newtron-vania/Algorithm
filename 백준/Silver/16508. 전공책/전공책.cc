#include <bits/stdc++.h>

using namespace std;
    
int books_alpha[16][26] = {0, };
int costs[16] = {0, };
int check[26] = {0, };

bool canMake(int alpha[26])
{
    for(int i = 0; i < 26; i++)
    {
        if(check[i] > alpha[i]) return false;
    }
    return true;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string input;
    cin >> input;
    
    for(const auto& c : input)
    {
        check[c - 'A'] += 1;
    }
    
    int n;
    cin >> n;

    // 제목 알파벳 개수 및 가격 입력
    for(int i = 0; i < n; i++)
    {
        int cost;
        string title;
        
        cin >> cost >> title;
        
        for(int k = 0; k < title.size(); k++)
        {
            books_alpha[i][title[k] - 'A'] += 1;
        }
        costs[i] = cost;
    }
    
    int result = -1;
    for(int i = 1; i < (1 << n); i++)
    {
        int sum = 0;
        int alpha[26] = {0, };
        for(int j = 0; j < n; j++)
        {
            if(i & (1 << j))
            {
                sum += costs[j];
                for(int k = 0; k < 26; k++)
                {
                    alpha[k] += books_alpha[j][k];
                }
            }
        }
        
        if(canMake(alpha) && (result < 0 || result > sum)) result = sum;
    }
    
    cout << result << endl;
}