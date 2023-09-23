#include <string>
#include <vector>

using namespace std;

int TimeToMin(string time){
    return stoi(time.substr(0,2))*60 + stoi(time.substr(3,2));
}

const int MAXTIME = 60*24 + 10;
int solution(vector<vector<string>> book_time) {
    int answer = 0;
    int* plans = new int[MAXTIME];
    fill_n(plans, MAXTIME, 0);
    
    int max = 0;
    for(vector<string> time : book_time){
        int start = TimeToMin(time[0]);
        int end = TimeToMin(time[1]) + 10;
        for(int i = start; i < end; i++){
            plans[i]++;
            max = plans[i]>max ? plans[i] : max;
        }
    }
    answer = max;
    return answer;
}