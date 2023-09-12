#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    int day_count[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string days[] = {"SUN","MON","TUE","WED","THU","FRI","SAT"};
    int c_month = 1;
    int c_day = 5;
    int counting = 0;
    for(int i = 0; i < a-1; i++){
        counting += day_count[i];
    }
    counting += b-1;
    answer = days[(c_day + counting) % 7];
    return answer;
}