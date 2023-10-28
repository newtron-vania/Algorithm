#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <iostream>

using namespace std;



vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    map<string, int> map_course;
    
    for(string order : orders)
    {
        sort(order.begin(), order.end());
        set<string> set_tmp;
        do{
            //확인할 코스의 길이별로 탐색
            for(int len : course)
            {
                string str_tmp = order.substr(0, len);
                sort(str_tmp.begin(), str_tmp.end());
                set_tmp.insert(str_tmp);
            }
        }while(next_permutation(order.begin(), order.end()));
        
        for(auto iter = set_tmp.begin(); iter != set_tmp.end(); iter++)
        {
            map_course[*iter] += 1;
        }
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