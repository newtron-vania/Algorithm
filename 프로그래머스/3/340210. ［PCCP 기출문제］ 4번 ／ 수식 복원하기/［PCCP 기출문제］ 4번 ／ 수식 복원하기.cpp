#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> Split(string str)
{
    stringstream sst(str);
    string buf;
    vector<string> result;
    while (getline(sst, buf, ' '))
    {
        result.push_back(buf);
    }
    return result;
}

int convertBaseToDecimal(int num, int base)
{
    int result = 0;
    int multiplier = 1;
    while (num > 0)
    {
        if (num % 10 >= base)
        {
            return -1;
        }
        result += (num % 10) * multiplier;
        multiplier *= base;
        num /= 10;
    }
    return result;
}

int convertDecimalToBase(int num, int base)
{
    int result = 0;
    int multiplier = 1;
    while (num > 0)
    {
        result += (num % base) * multiplier;
        multiplier *= 10;
        num /= base;
    }
    return result;
}

vector<int> getInvalidBases(vector<string> expression)
{
    int A, B, C;
    vector<int> invalidBases;
    for (int i = 2; i < 10; i++)
    {
        A = convertBaseToDecimal(stoi(expression[0]), i);
        B = convertBaseToDecimal(stoi(expression[2]), i);
        if (expression[4] == "X")
        {
            if (A < 0 || B < 0)
            {
                invalidBases.push_back(i);
            }
        }
        else
        {
            C = convertBaseToDecimal(stoi(expression[4]), i);
            if (A < 0 || B < 0 || C < 0)
            {
                invalidBases.push_back(i);
                continue;
            }
            if (expression[1] == "-")
            {
                if (A - B != C)
                {
                    invalidBases.push_back(i);
                }
            }
            else
            {
                if (A + B != C)
                {
                    invalidBases.push_back(i);
                }
            }
        }
    }
    return invalidBases;
}

vector<string> solution(vector<string> expressions)
{
    vector<string> answer;
    vector<vector<string>> tempExpressions;
    vector<bool> validBases(10, true);

    for (int i = 0; i < expressions.size(); i++)
    {
        vector<string> temp = Split(expressions[i]);
        if (temp[4] == "X")
        {
            tempExpressions.push_back(temp);
        }
        vector<int> invalidBases = getInvalidBases(temp);
        for (int base : invalidBases)
        {
            validBases[base] = false;
        }
    }

    vector<int> validBaseList;
    for (int i = 2; i < 10; i++)
    {
        if (validBases[i])
        {
            validBaseList.push_back(i);
        }
    }

    for (int i = 0; i < tempExpressions.size(); i++)
    {
        int A, B, C, compareC;
        bool isConsistent = true;

        A = convertBaseToDecimal(stoi(tempExpressions[i][0]), validBaseList[0]);
        B = convertBaseToDecimal(stoi(tempExpressions[i][2]), validBaseList[0]);
        if (tempExpressions[i][1] == "+")
        {
            C = convertDecimalToBase(A + B, validBaseList[0]);
        }
        else
        {
            C = convertDecimalToBase(A - B, validBaseList[0]);
        }

        for (int j = 1; j < validBaseList.size(); j++)
        {
            A = convertBaseToDecimal(stoi(tempExpressions[i][0]), validBaseList[j]);
            B = convertBaseToDecimal(stoi(tempExpressions[i][2]), validBaseList[j]);
            if (tempExpressions[i][1] == "+")
            {
                compareC = convertDecimalToBase(A + B, validBaseList[j]);
            }
            else
            {
                compareC = convertDecimalToBase(A - B, validBaseList[j]);
            }
            if (compareC != C)
            {
                isConsistent = false;
                tempExpressions[i][4] = "?";
                break;
            }
        }

        if (isConsistent)
        {
            tempExpressions[i][4] = to_string(C);
        }

        string formattedExpression = "";
        for (int j = 0; j < 4; j++)
        {
            formattedExpression += tempExpressions[i][j] + " ";
        }
        formattedExpression += tempExpressions[i][4];
        answer.push_back(formattedExpression);
    }

    return answer;
}
