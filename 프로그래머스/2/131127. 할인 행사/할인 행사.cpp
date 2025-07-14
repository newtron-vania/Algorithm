#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool CanSale(vector<int> number) {
    for (vector<int>::iterator i = number.begin(); i != number.end(); i++) {
        if (*i > 0) return false;
    }
    return true;
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    for (int i = 0; i < 10; i++) {
        // 해당 문자열 찾아서 갯수 줄이기
        auto it = find(want.begin(), want.end(), discount[i]);
        if (it != want.end()) number[it - want.begin()] -= 1;
    }
    int discountSize = 0;
    if (CanSale(number)) discountSize += 1;
    answer = discountSize;
    for (int i = 10; i < discount.size(); i++) {
        auto it = find(want.begin(), want.end(), discount[i - 10]);
        if (it != want.end()) number[it - want.begin()] += 1;
        it = find(want.begin(), want.end(), discount[i]);
        if (it != want.end()) number[it - want.begin()] -= 1;

        if (CanSale(number)) discountSize += 1;
    }
    if (answer < discountSize) answer = discountSize;
    return answer;
}