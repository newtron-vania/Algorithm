#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;



string solution(string s) {
    string answer = "";
    
    stringstream ss(s);
    int num;
    
    vector<int> vec;
    
    while(ss >> num)
    {
        vec.push_back(num);
    }
    
    sort(vec.begin(), vec.end());
    
    answer += to_string(*(vec.begin())) + " " +to_string(*(vec.end()-1));
    
    return answer;
}

