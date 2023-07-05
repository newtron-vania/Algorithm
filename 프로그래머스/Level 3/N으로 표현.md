- 주소 - https://school.programmers.co.kr/learn/courses/30/lessons/42895#

###### 문제 설명

아래와 같이 5와 사칙연산만으로 12를 표현할 수 있습니다.

12 = 5 + 5 + (5 / 5) + (5 / 5)
12 = 55 / 5 + 5 / 5
12 = (55 + 5) / 5

5를 사용한 횟수는 각각 6,5,4 입니다. 그리고 이중 가장 작은 경우는 4입니다.
이처럼 숫자 N과 number가 주어질 때, N과 사칙연산만 사용해서 표현 할 수 있는 방법 중 N 사용횟수의 최솟값을 return 하도록 solution 함수를 작성하세요.

##### 제한사항

- N은 1 이상 9 이하입니다.
- number는 1 이상 32,000 이하입니다.
- 수식에는 괄호와 사칙연산만 가능하며 나누기 연산에서 나머지는 무시합니다.
- 최솟값이 8보다 크면 -1을 return 합니다.

##### 입출력 예

| N    | number | return |
| ---- | ------ | ------ |
| 5    | 12     | 4      |
| 2    | 11     | 3      |

##### 입출력 예 설명

예제 #1
문제에 나온 예와 같습니다.

예제 #2
`11 = 22 / 2`와 같이 2를 3번만 사용하여 표현할 수 있습니다.

##### 문제풀이
###### 1. DP 및 BFS - 실패
- 음수의 결과값을 dp로 저장하지 못함
```c++
  #include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <iostream>
const int MAX = 100000000;

using namespace std;

int solution(int N, int number) {
    int answer = 0;
    int dp[MAX];
    fill_n(dp, MAX, 9);
    queue<int> q;
    int k = N;
    for(int i = 1; i <= 7; i++){
        dp[k] = i;
        q.push(k);
        k = k*10+ N;
    }
    int arr[4];
    while(!q.empty()){
        int x = q.front();
        q.pop();
        if(dp[x]> 8 || x<= 0)
            continue;
        if(x == number)
            return dp[x];
        arr[0] = x+N < MAX ? x+N : MAX-1;
        arr[1] = x-N > 0 ? x-N : 1;
        arr[2] = x*N < MAX ? x*N : MAX-1;
        arr[3] = x/N;
        
        for(int i = 0; i < 4; i++){
            if(i == 3 && x%N != 0)
                continue;
            if(dp[arr[i]] > dp[x]+1){
                dp[arr[i]] = dp[x]+1;
                q.push(arr[i]);
            }
        }
    }

    return -1;
}
```
###### 2. DP + 집합으로 풀이
- 숫자를 사용한 횟수별 결괏값을 각각 저장
- 현재 찾는 횟수보다 낮은 횟수별 결괏값끼리 사칙연산을 실시하여 현재 횟수의 결괏값을 저장
- ex) 3개 숫자를 쓴 결괏값은 1개 숫자를 쓴 결괏값들과 3개 숫자를 쓴 결괏값들끼리의 사칙연산 + 2개 숫자를 쓴 결괏값들끼리의 사칙연산으로 이루어져 있다.
- 3개 이상의 조합은 2개의 조합에 포함되므로 필요 없다.

```c++
#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <iostream>

using namespace std;

int solution(int N, int number) {
    int answer = 0;
    set<int> dp[9];
    int k = 0;
    for(int i = 1; i < 9; i++){
        k = k *10 + N;
        dp[i].insert(k);
    }
     
    for(int i = 1; i <= 8; i++){
        for(int j = 1; j < i; j++){
            for(int a : dp[j]){
                for(int b : dp[i - j]){
                    dp[i].insert(a + b);
                    dp[i].insert(a-b);
                    dp[i].insert(a*b);
                    if(b != 0 && a%b == 0)
                        dp[i].insert(a/b);
                }
            }
        }
        if(dp[i].find(number) != dp[i].end())
            return i;
    }
    return -1;
}
```
