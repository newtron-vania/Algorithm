#include <string>
#include <vector>
using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges)
{
    vector<double> answer;
    vector<pair<int,int>> v;
    v.push_back({0,k});
    for(int i=1;k!=1;i++)
    {
        if(k%2) k = 3*k +1;
        else k /=2;
        v.push_back({i, k});
    }
    for(auto c : ranges)
    {
        int s = c[0], e = v.size()-1+c[1];
        double res = 0;
        for(int i=s;i<e;i++)
            res += (double)(v[i].second+v[i+1].second)/2;
        if (s>e) answer.push_back(-1.0);
        else answer.push_back(res);
    }
    return answer;
}