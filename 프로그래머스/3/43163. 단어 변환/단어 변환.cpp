#include <string>
#include <vector>
const int MAX_INT = 987654321;
using namespace std;

void dfs(int count, string begin, string target, int& answer, vector<string>& words, vector<bool>& visited) {
    if (begin.compare(target) == 0) {
        answer = min(answer, count);
        return;
    }
    count++;
    int countDiff;
    for (int k = 0; k < words.size(); k++) {
        countDiff = 0;
        for (int i = 0; i < words[k].length(); i++) {
            if (begin[i] != words[k][i]) {
                countDiff++; if (countDiff > 1) break;
            }
        }
        if (countDiff == 1 && !visited[k]) {
            visited[k] = true;
            dfs(count, words[k], target, answer, words, visited);
            visited[k] = false;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    int answer = MAX_INT;
    vector<bool> visited(words.size());
    dfs(0, begin, target, answer, words, visited);
    return (answer != MAX_INT) ? answer : 0;
}