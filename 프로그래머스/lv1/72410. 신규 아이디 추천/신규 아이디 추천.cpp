#include <string>
#include <vector>
#include <regex>
#include <iostream>

using namespace std;


string solution(string new_id) {
    int cnt = 1;
    //1단계
    for (auto& i : new_id) {
        i = tolower(i);
    }

    //2단계
    new_id = regex_replace(new_id, regex("[^a-z0-9-_.]"), "");

    //3단꼐
    new_id = regex_replace(new_id, regex("[.]+"), ".");

    //4단계

    if (!new_id.empty() && new_id[0] == '.') { new_id.erase(new_id.begin()); }

    if (!new_id.empty() && new_id[new_id.length()-1] == '.') {  new_id.erase(new_id.end()-1); }
  

    //5단계
    if (new_id.empty()) new_id += "a";
    //6단계
    if (new_id.length() >= 16) {
        new_id.erase(15);

        if (new_id.back() == '.') new_id.erase(new_id.end()-1);
    }

    //7단계
    if (new_id.length() <= 2)
        do {
            new_id += new_id.back();
        } while (new_id.length() < 3);


    return new_id;
}
