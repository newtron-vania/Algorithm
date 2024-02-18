#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    int result = 0;

    sort(timetable.begin(), timetable.end());
    vector<int> timeTable;
    for (auto& time : timetable)
        timeTable.push_back(stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2)));

    int index = 0;
    int busTime = 540; // 09:00
    for (int count = 1; count <= n; ++count) {
        int numOfGetOn = 0;
        while (numOfGetOn < m && index < timeTable.size()) {
            if (timeTable[index] <= busTime) {
                numOfGetOn++;
                index++;
            }
            else break;
        }
        
        if (count == n) {
            if (numOfGetOn < m)
                result = busTime;
            else
                result = timeTable[index - 1] - 1;
        }
        busTime += t;
    }
  
    int hours = result / 60;
    if (hours <= 9)
        answer = "0" + to_string(hours) + ":";
    else
        answer = to_string(hours) + ":";

    int minutes = result % 60;
    if (minutes <= 9)
        answer += "0" + to_string(minutes);
    else
        answer += to_string(minutes);

    return answer;
}