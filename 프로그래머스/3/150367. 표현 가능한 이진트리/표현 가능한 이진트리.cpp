#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 이진트리 체크 함수
bool IsBitTree(string number)
{
    int mid = (number.length() / 2); // 중간 위치를 찾음
    // 모든 비트가 0인지 체크
    for(int idx = 0; idx < number.length(); idx++)
    {
        if(number[idx] - '0' != 0)
            break;
        if(idx == number.length() - 1)
            return true;
    }
    // 중간 비트가 0이면 false 반환
    if(number[mid] - '0' == 0)
    {
        return false;
    }
    // 길이가 3 이하이면 true 반환
    else if(number.length() <= 3){
        return true;
    }

    // 좌, 우측 서브트리로 나눔
    string left = number.substr(0, mid);
    string right = number.substr(mid + 1);
    // 재귀적으로 좌, 우측 서브트리 체크
    if(IsBitTree(left) && IsBitTree(right))
    {
        return true;
    }
    else{
        return false;
    }
}

// 이진수로 변환
string MakeBit(long long number)
{
    string result = "";
    // 비트 연산을 통해 이진수 생성
    while(number > 0)
    {
        result = to_string(number & 1) + result;
        number >>= 1;
    }
    // 이진수의 길이를 2의 거듭제곱 근접으로 맞춤
    int length = result.length();
    int zero_count = 1;
    while(zero_count <= length)
    {
        zero_count *= 2;
    }
    for(int i = length; i < zero_count - 1; i++)
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
        string num = MakeBit(number); // 이진수 변환
        answer.push_back((int)IsBitTree(num)); // 이진트리 여부 확인 후 결과 저장
    }

    return answer;
}
