#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <iostream>

using namespace std;

struct File {
    string filename;
    string HEAD = "";
    int NUMBER = 0;
    File(string filename) {
        this->filename = filename;
        int idx = 0;
        //HEAD 
        while (!isdigit(filename[idx])) {
            HEAD += tolower(filename[idx++]);
        }
        //NUMBER
        string num_str = "";
        while (isdigit(filename[idx]) && num_str.length() < 5) {
            num_str += filename[idx++];
        }
        NUMBER = stoi(num_str);
    }
};

bool comp(File a, File b) {
    if (a.HEAD == b.HEAD) {
        if (a.NUMBER == b.NUMBER) {
            return false;
        }
        else {
            return a.NUMBER < b.NUMBER;
        }
    }
    else {
        return a.HEAD < b.HEAD;
    }
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<File> fileVec;
    for (string file : files) {
        fileVec.push_back(File(file));
    }
    stable_sort(fileVec.begin(), fileVec.end(), comp);
    for (File file : fileVec) {
        answer.push_back(file.filename);
    }
    return answer;
}