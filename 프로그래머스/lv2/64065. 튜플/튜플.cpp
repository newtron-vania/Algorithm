#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

const int MAX = 501;

bool comp(pair<int, int>& a, pair<int, int>& b){
    return a.second > b.second;
}

vector<int> solution(string s) {
    vector<int> answer;
    unordered_map<int, int> n_cnts;
    
    int idx = 0;
    while(idx < s.length()){
        string tmp = "";
        
        while(isdigit(s[idx])){
            tmp += s[idx];
            idx++;
        }
        
        idx++;
        if(tmp.empty())
            continue;
        n_cnts[stoi(tmp)] += 1;
        
    }
    vector<pair<int, int>> n_vec(n_cnts.begin(), n_cnts.end());
    
    sort(n_vec.begin(), n_vec.end(), comp);
    for(auto& itr : n_vec){
        answer.push_back(itr.first);
    }
    
    return answer;
}