#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    vector<vector<int>> triangle_result(triangle);
    for(int i = 0; i < triangle.size()-1; i++){
        for(int j = 0; j < triangle[i].size(); j++){
            triangle_result[i+1][j] = 
                max(triangle_result[i+1][j], triangle_result[i][j] + triangle[i+1][j]);
            triangle_result[i+1][j+1] = 
                max(triangle_result[i+1][j+1], triangle_result[i][j] + triangle[i+1][j+1]);
        }
    }
    
    vector<int> triangle_last(triangle_result.back());
    int answer = *max_element(triangle_last.begin(), triangle_last.end());
    return answer;
}