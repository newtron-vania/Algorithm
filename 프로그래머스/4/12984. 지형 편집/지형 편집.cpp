#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

long long solution(vector<vector<int> > land, int P, int Q) {
    long long answer = numeric_limits<long>::max();
    vector<int> land_vec;
    long long sum = 0;
    for(vector<int> l : land)
    {
        for(int r : l)
        {
            land_vec.push_back(r);
            sum += r;
        }
    }
    
    sort(land_vec.begin(), land_vec.end());
    
    long long prev = 0;
    int already = -1;
    for(int i = 0; i < land_vec.size(); i++)
    {
        if(already != land_vec[i])
        {
            already = land_vec[i];
            long long add_cnt = 1LL * land_vec[i] * i - prev;
            long long del_cnt = sum - prev - 1LL * land_vec[i] * (land_vec.size() - i);
            long long result = add_cnt * P + del_cnt * Q;
            answer = min(answer, result);
        }
        prev += land_vec[i];
    }
    return answer;
}