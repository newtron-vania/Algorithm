#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> lines) {
    int answer = 0;
    const int size = 201;
    int visited[size];
    fill_n(visited, size, 0);
    for(vector<int> line : lines){
        for(int i = line[0] + 100; i < line[1] + 100; i++){
            visited[i] += 1;
        }
    }
    
    for(int i = 0; i < size; i++){
        if(visited[i] > 1){
            cout << i-100 <<endl;
            answer += 1;
        }
    }
    return answer;
}