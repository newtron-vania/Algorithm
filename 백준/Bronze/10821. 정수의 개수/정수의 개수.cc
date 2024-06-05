#include <bits/stdc++.h>


using namespace std;

vector<string> split(string input, char delimiter);

int main()
{
    string ss;
    
    cin >> ss;
    
    auto nums = split(ss, ',');
    
    cout << nums.size();
    
    
    return 0;
}

vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;
 
    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }
 
    return answer;
}