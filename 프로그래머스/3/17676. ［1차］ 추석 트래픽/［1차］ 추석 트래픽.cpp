#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cmath>

using namespace std;

int process_count(double end_time, const vector<long>& start_times) {
    int count = 1;
    for (long start_time : start_times) {
        if (end_time > start_time) {
            count += 1;
        }
    }
    return count;
}

int solution(vector<string> lines) {
    vector<int> counts = {1};
    int answer = 0;

    vector<long> end_times;
    vector<long> processing_times;
    for (const string& line : lines) {
        istringstream iss(line);
        string timestamp, processing_time;
        iss >> timestamp >> timestamp >> processing_time;
        long end_time = (stoi(timestamp.substr(0, 2)) * 3600
                        + stoi(timestamp.substr(3, 2)) * 60 
                        + stoi(timestamp.substr(6, 2))) * 1000
                        + stoi(timestamp.substr(9));
        end_times.push_back(end_time);
        int processing_time_result = stoi(processing_time.substr(0, 1)) * 1000 + (processing_time[1] != '.' ? 0 : stoi(processing_time.substr(2, processing_time.size()-3)));
        processing_times.push_back(processing_time_result);
    }

    vector<long> start_times;
    for (int i = 0; i < end_times.size(); ++i) {
        start_times.push_back(end_times[i] - processing_times[i] + 1);
    }


    for (int i = 0; i < end_times.size() - 1; ++i) {
        counts.push_back(process_count(end_times[i] + 1000, vector<long>(start_times.begin() + i + 1, start_times.end())));
    }

    answer = *max_element(counts.begin(), counts.end());

    return answer;
}