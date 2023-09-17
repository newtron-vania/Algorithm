#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;

    sort(people.begin(), people.end(), greater<>());

    for (int i = 0; people[i] == limit; i++)
    {
        answer++;
    }

    for (int i = answer; i < people.size(); i++)
    {
        int limitNew = limit - people[i];
        //for (int j = i + 1; j < people.size(); j++)
        for (int j = people.size() - 1; j > i; j--)
        {
            if (people[j] > limitNew)
                break;
            else if (people[j] == limitNew || (people[j] < limitNew && (j - 1 <= i || people[j - 1] > limitNew))) //같거나 다음 친구가 여의치 않으면 걍 지우고
            {
                people.erase(people.begin() + j); //같은 경우
                break;
            }
        }
        answer++;
    }

    return answer;
}