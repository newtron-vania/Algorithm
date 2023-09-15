#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool comp(vector<int> a, vector<int> b){
    if(a[2] == b[2])
        return a[0] < b[0];
    return a[2] < b[2];
}

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    vector<vector<int>> seq_vec;
    int start=0, end = 0, sum = 0;
    while(end < sequence.size()){
        sum += sequence[end];
        while(sum >= k){
            if(sum == k){
                seq_vec.push_back({start, end, end-start});
            }
            sum -= sequence[start];
            start += 1;
        }
        end += 1;
    }
    sort(seq_vec.begin(), seq_vec.end(), comp);
    answer = vector<int>(seq_vec[0].begin(), seq_vec[0].begin() + 2);
    return answer;
}