#include <bits/stdc++.h>

using namespace std;

vector<string> Split(string str, char Delimiter)
{
    istringstream iss(str);             // istringstream에 str을 담는다.
    string buffer;                      // 구분자를 기준으로 절삭된 문자열이 담겨지는 버퍼
 
    vector<string> result;
 
    // istringstream은 istream을 상속받으므로 getline을 사용할 수 있다.
    while (getline(iss, buffer, Delimiter)) 
    {
        result.push_back(buffer);               // 절삭된 문자열을 vector에 저장
    }
 
    return result;
}

// 주어진 숫자를 n진법으로 변환하여 10진수로 계산
int convertToDecimal(const string &number, int base)
{
    int result = 0;
    for (char ch : number)
    {
        result = result * base + (ch - '0');
    }
    return result;
}

// 연산 수식을 10진법으로 검증
bool isValidExpression(const string &A, const string &B, const string &C, string op, int base)
{
    int a = convertToDecimal(A, base);
    int b = convertToDecimal(B, base);
    int c = convertToDecimal(C, base);

    if (op == "+")
    {
        return a + b == c;
    }
    else
    {
        return a - b == c;
    }
}

// 주어진 진법 후보군으로 모르는 수식을 해결
string solveUnknownExpression(const string &expression, const vector<int> &bases)
{
    vector<string> words = Split(expression, ' ');
            
    string A = words[0];
    string op = words[1];
    string B = words[2];
    string C = words[4];

    unordered_set<string> possibleResults;
    for (int base : bases)
    {
        int a = convertToDecimal(A, base);
        int b = convertToDecimal(B, base);
        int result = (op == "+") ? a + b : a - b;
        string cBase = "";

        // 결과값을 현재 진법으로 변환
        do 
        {
            cBase = char((result % base) + '0') + cBase;
            result /= base;
        }while(result > 0);

        // 변환한 결과값을 저장
        if (cBase == C || C == "X")
        {
            possibleResults.insert(cBase);
        }
    }

    // 결과가 여러 가지이면 ?
    if (possibleResults.size() != 1)
    {
        return expression.substr(0, expression.length() - 1) + "?";
    }
    else
    {
        return expression.substr(0, expression.length() - 1) + *possibleResults.begin();
    }
}

vector<string> solution(vector<string> expressions)
{
    vector<string> knownExpressions;
    vector<string> unknownExpressions;

    // 수식을 아는 것과 모르는 것으로 분리
    for (const string &expr : expressions)
    {
        if (expr.back() == 'X')
        {
            unknownExpressions.push_back(expr);
        }
        else
        {
            knownExpressions.push_back(expr);
        }
    }

    int maxDigit = 2;

    // 최대 숫자를 찾아 최소 진법 후보군을 계산
    for (const string &expr : expressions)
    {
        for (char ch : expr)
        {
            if (isdigit(ch))
            {
                maxDigit = max(maxDigit, ch - '0' + 1);
            }
        }
    }

    vector<int> possibleBases;
    for (int base = max(maxDigit, 2); base <= 9; ++base)
    {
        bool validBase = true;
        for (const string &expr : knownExpressions)
        {
            vector<string> words = Split(expr, ' ');
            
            string A = words[0];
            string op = words[1];
            string B = words[2];
            string C = words[4];

            if (!isValidExpression(A, B, C, op, base))
            {
                validBase = false;
                break;
            }
        }
        if (validBase)
        {
            possibleBases.push_back(base);
        }
    }
    

    vector<string> result;
    for (const string &expr : unknownExpressions)
    {
        result.push_back(solveUnknownExpression(expr, possibleBases));
    }

    return result;
}