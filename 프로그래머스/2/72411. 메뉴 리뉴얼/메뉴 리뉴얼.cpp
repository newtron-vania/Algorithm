#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <iostream>

using namespace std;

void combination(string src, string crs ,int depth, map<string, int>& map_course )
{
    if(crs.length() == depth) { map_course[crs] += 1; return; }
    
    for(int i = 0; i < src.length(); i++)
    {
        combination(src.substr(i+1), crs + src[i], depth, map_course);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    map<string, int> map_course;
    
    for(string order : orders)
    {
        sort(order.begin(), order.end());
        for(int len : course) { combination(order, "", len, map_course ); }
        
    }
    

    for (int len : course) {
        int max_count = 2; // 가장 작은 코스 길이에 대한 최소 주문 횟수를 설정
        for (auto it = map_course.begin(); it != map_course.end(); it++) {
            if (it->first.length() == len && it->second >= max_count) {
                max_count = it->second;
            }
        }
        for (auto it = map_course.begin(); it != map_course.end(); it++) {
            if (it->first.length() == len && it->second == max_count) {
                answer.push_back(it->first);
            }
        }
    }

    sort(answer.begin(), answer.end());
    
    return answer;
}