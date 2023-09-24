#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    int size = arr1.size();
    for(int i = 0; i < size; i++){
        int sum = arr1[i] | arr2[i];
        string str = "";
        for(int j = 0; j < size; j++){
            if(sum%2) str = "#" + str;
            else str = " " + str;
            sum >>= 1;
        }
        answer.push_back(str);
    }
    return answer;
}