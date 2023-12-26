#include <string>
#include <vector>
#include <unordered_set>
#include <climits>
#include <algorithm>

using namespace std;

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1, T2>& p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);

        return h1 ^ h2;
    }
};

vector<string> solution(vector<vector<int>> line) {
    vector<string> answer;
    unordered_set<pair<int, int>,pair_hash> locations;
    for(int i = 0; i < line.size(); i++)
    {
        vector<int> A = line[i];
        for(int j = i+1; j < line.size(); j++)
        {
            vector<int> B = line[j];
            long long mod = 1LL * A[0] * B[1] - 1LL* A[1] * B[0];
            if(mod != 0)
            {
                long long x = 1LL * A[1] * B[2] - 1LL * A[2] * B[1];
                long long y = 1LL * A[2] * B[0] - 1LL * A[0] * B[2];
                if(!(x % mod) && !(y % mod))
                {
                    locations.insert(pair(x / mod, y / mod));
                }
            }
        }
    }
    
    int x_min = INT_MAX;
    int y_min = INT_MAX;
    int x_max = INT_MIN;
    int y_max = INT_MIN;
    
    for(const auto& location : locations)
    {
        int x = location.first;
        int y = location.second;
        x_min = min(x_min, x);
        y_min = min(y_min, y);
        x_max = max(x_max, x);
        y_max = max(y_max, y);
    }
    long long x_size = x_max - x_min;
    long long y_size = y_max - y_min;
    string star_string = "";
    for(long long i = 0; i <= x_size; i++)
    {
        star_string += '.';
    }
    answer = vector<string>(y_size+1, star_string);
    for(const auto & location : locations)
    {
        int x = abs(location.first - x_min);
        int y = abs(location.second - y_max);
        answer[y][x] = '*';

    }
    
    
    return answer;
}