#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    map<string, string> e;
    map<string, int> s;
    
    for (int i = 0; i < enroll.size(); i++) 
    {
        if (referral[i] == "-") 
        {
            e[enroll[i]] = "-";
        }
        else 
        {
            e[enroll[i]] = referral[i];
        }
    }
    
    for (int i = 0; i < seller.size(); i++) 
    {
        int val = amount[i] * 100;
        string name = seller[i];
        
        while (name != "-") 
        {
            int vat = val * 0.1;
            s[name] += val - vat;
            val = vat;
            name = e[name];
            if (vat < 1) 
            {
                break;
            }
        }
    }
    
    for (int i = 0; i < enroll.size(); i++) 
    {
        answer.push_back(s[enroll[i]]);
    }
    
    return answer;
}