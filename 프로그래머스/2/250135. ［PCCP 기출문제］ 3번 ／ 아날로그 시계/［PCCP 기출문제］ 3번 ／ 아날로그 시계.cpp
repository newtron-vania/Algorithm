#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class ClockTime {
public:
    int hours, minutes, seconds;

    ClockTime(int totalSeconds) {
        this->hours = totalSeconds / 3600;
        this->minutes = (totalSeconds % 3600) / 60;
        this->seconds = (totalSeconds % 3600) % 60;
    }

    int TimeToSec() {
        return hours * 3600 + minutes * 60 + seconds;
    }

    vector<double> CalculateDegrees() {
        double hourDegree = (hours % 12) * 30.f + minutes * 0.5f + seconds * (1/120);
        double minuteDegree = minutes * 6.f + seconds * 0.1f;
        double secondDegree = seconds * 6.f;

        return vector<double>{hourDegree, minuteDegree, secondDegree};
    }
};

bool isHourOverlap(vector<double> currentDegrees, vector<double> nextDegrees) {
    if(currentDegrees[0] > currentDegrees[2] && nextDegrees[0] <= nextDegrees[2]) {
        return true;
    }

    if(currentDegrees[2] == 354 && currentDegrees[0] > 354) {
        return true;
    }
    return false;
}

bool isMinuteOverlap(vector<double> currentDegrees, vector<double> nextDegrees) {
    if(currentDegrees[1] > currentDegrees[2] && nextDegrees[1] <= nextDegrees[2]) {
        return true;
    }

    if(currentDegrees[2] == 354 && currentDegrees[1] > 354) {
        return true;
    }
    
    return false;
}

int solution(int startHours, int startMinutes, int startSeconds, int endHours, int endMinutes, int endSeconds) {
    int answer = 0;

    int start = ClockTime(startHours * 3600 + startMinutes * 60 + startSeconds).TimeToSec();
    int end = ClockTime(endHours * 3600 + endMinutes * 60 + endSeconds).TimeToSec();

    for(int i = start; i < end; i++) 
    {
        vector<double> currentDegrees = ClockTime(i).CalculateDegrees();
        vector<double> nextDegrees = ClockTime(i + 1).CalculateDegrees();

        bool hourOverlap = isHourOverlap(currentDegrees, nextDegrees);
        bool minuteOverlap = isMinuteOverlap(currentDegrees, nextDegrees);
        
        if(hourOverlap && minuteOverlap) 
        {
            if(nextDegrees[0] == nextDegrees[1]) answer++;
            else answer += 2;
        } 
        
        else if(hourOverlap || minuteOverlap) answer++;
    }

    if(start == 0 || start == 43200) answer++;
    
    return answer;
}