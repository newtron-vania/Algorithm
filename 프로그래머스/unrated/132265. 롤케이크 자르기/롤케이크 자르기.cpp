#include <string>
#include <vector>
#include <iostream>

using namespace std;
const int MAXIMUM = 10001;
int solution(vector<int> topping) {
    int answer = 0;
    int* arr = new int[MAXIMUM];
    bool* visited = new bool[MAXIMUM];
    int topping_size = 0;
    fill_n(arr, MAXIMUM, -1);
    fill_n(visited, MAXIMUM, false);
    for(int num : topping){
        if(arr[num] < 0){
            topping_size++;
            arr[num] = 0;
        }
        arr[num]++;
    }
    
    int left = 0;
    int right = topping_size;
    for(int num : topping){
        if(!visited[num]){
            visited[num] = true;
            left++;
        }

        arr[num]--;
        if(arr[num] == 0){
            right--;
        }

        if(left == right){
            answer++;
        }

        if(left > right)
            break;
    }
    return answer;
}