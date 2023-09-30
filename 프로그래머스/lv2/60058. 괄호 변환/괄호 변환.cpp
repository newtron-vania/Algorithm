#include <iostream>
#include <string>

using namespace std;

pair<string, string> splitUAndV(string word) {
    int left = 0;
    int right = 0;
    bool isCorrect = false;

    if (word[0] == '(') {
        isCorrect = true;
        left += 1;
    } else {
        isCorrect = false;
        right += 1;
    }

    int i = 1;
    while (left != right) {
        if (word[i] == '(') {
            left += 1;
        } else {
            right += 1;
        }
        i += 1;
    }

    string u = word.substr(0, i);
    string v = word.substr(i);

    return make_pair(u, v);
}

string dfs(string word) {
    if (word == "") {
        return "";
    }

    pair<string, string> uv = splitUAndV(word);
    string u = uv.first;
    string v = uv.second;

    v = dfs(v);

    if (u[0] == '(') {
        return u + v;
    } else {
        string answer = "(" + v + ")";
        for (int w = 1; w < u.length() - 1; w++) {
            if (u[w] == '(') {
                answer += ")";
            } else {
                answer += "(";
            }
        }
        return answer;
    }
}

string solution(string p) {
    string answer = dfs(p);
    return answer;
}