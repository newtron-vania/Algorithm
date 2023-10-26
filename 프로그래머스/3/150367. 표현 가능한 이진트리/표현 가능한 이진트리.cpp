#include <string>
#include <vector>
#include <iostream>

using namespace std;

//111 - 7
//0101010 - 42
//101 - 5
//0111111 - 63
//1101111 - 111
//1011111 - 95

//이진트리 체크 함수
bool IsBitTree(string number)
{
    int mid = (number.length() / 2);
    for(int idx = 0; idx < number.length(); idx++)
    {
        if(number[idx] - '0' != 0)
            break;
        if(idx == number.length()-1)
            return true;
    }
    if(number[mid] - '0' == 0)
    {
        return false;
    }
    else if(number.length() <= 3){
        return true;
    }

    string left = number.substr(0,mid);
    string right = number.substr(mid+1);
    if(IsBitTree(left) && IsBitTree(right))
    {
        return true;
    }
    else{
        return false;
    }
}

//이진수로 변환
string MakeBit(long long number)
{
    string result = "";
    while(number > 0)
    {
        result = to_string(number & 1) + result;
        number >>= 1;
    }
    int length = result.length();
    int zero_count = 1;
    while(zero_count <= length)
    {
        zero_count *= 2;
    }
    for(int i = length; i < zero_count-1; i++)
    {
        result = '0' + result;
    }
    return result;
}
vector<int> solution(vector<long long> numbers) 
{
    vector<int> answer;
    for(long long number : numbers)
    {
        string num = MakeBit(number);
        answer.push_back((int)IsBitTree(num));
    }

    return answer;
}