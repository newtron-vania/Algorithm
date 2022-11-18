'''
문제
선우는 APC 문제를 만들기 위해 고민하며 역대 APC들을 둘러보던 와중, 이 대회들의 문제가 난이도가 쉬운 순으로 배치되어 있는 경향을 발견했다! 문제 출제가 완료되고 올해도 이러한 기조를 지키려고 한 선우는 출제하기로 한 문제들에 예상 난이도를 매겨놓았다.

난이도는 브론즈 티어, 실버 티어, 골드 티어, 플래티넘 티어, 다이아몬드 티어 순으로 어려워지며, 동일 난이도가 없도록 엄밀한 구별을 위하여 각각의 티어에 $1$에서 $1\,000$ 사이의 수를 매겨놓기로 하였다. 동일 티어에서는 수가 작을수록 어려운 것을 의미한다. 예를 들어서 브론즈 티어 $1$ 단계의 문제는 브론즈 티어 $1\,000$ 단계의 문제보다 어렵고, 실버 티어 $1\,000$ 단계의 문제는 브론즈 티어 $1$ 단계의 문제보다 어렵다. 이후 선우는 문제를 난이도의 오름차순으로 정렬해놓았다.

그러나 각각 작년과 올해에 아주대학교 소프트웨어 학과 알고리즘 소학회인 A.N.S.I. 회장을 하며 지쳐있었던 또 다른 APC 출제자 의찬이와 지수는 정신적으로 힘들었던 나머지 합심하여 트롤링을 저지를 계획을 세운다.

의찬, 지수: 헤헷

그 트롤링 계획은 바로 둘이서 잘 정렬되어 있었던 문제 중 랜덤하게 두 개를 골라 순서를 바꾸어놓는 것이었다!

둘이서 이를 계획했다는 것을 눈치채어 머리가 지끈지끈해진 선우는 빨리 이를 복구하고자 한다. 선우를 도와주는 프로그램을 만들어주자.
=============================================
입력
첫째 줄에 문제의 수 $N$이 주어진다. ($2 ≤ N ≤ 1\,000$)

둘째 줄에 배치되어 있는 문제의 난이도 $N$개가 공백을 사이에 두고 주어진다. 문제의 티어는

브론즈: B
실버: S
골드: G
플래티넘: P
다이아몬드: D
로 표기되며, 난이도는 {티어}{단계}로 주어진다. 예를 들어서 브론즈 티어 $1\,000$ 단계의 문제는 B1000, 다이아몬드 티어 $1$ 단계의 문제는 D1로 표기된다.

모든 문제의 난이도는 서로 다르게 주어진다.
=============================================
출력
의찬이와 지수가 계획을 실행에 옮기지 않아 문제들의 난이도가 쉬운 순으로 잘 배치되어 있다면 OK를 출력한다.

그렇지 않다면 첫째 줄에 KO를 출력하고, 잘못 배치된 문제 $2$개의 난이도를 난이도가 쉬운 순서대로 출력한다.

 $3$개 이상의 난이도가 뒤섞여 있는 경우는 없다. 즉, 순서 바꾸기는 최대 한 번만 발생한다.

=============================================
예제 입력 1 
6
B50 S999 S1 G5 P3 D1
예제 출력 1 
OK
=============================================
예제 입력 2 
2
D1 B1
예제 출력 2 
KO
B1 D1
=============================================
예제 입력 3 
5
B1 P1 G1 S1 D1
예제 출력 3 
KO
S1 P1
=============================================
'''

#람다식을 이용한 리스트 정렬이 주요 골자. 이 문제를 통해 lambda식의 사용법을 더 능숙해진것을 느꼈다.
'''
lambda x : lambda x: [rank[x[0]],-int(x[1:])]

equal

def fuction(x):
    return rank[x[0]], -int(x[1:])

'''


n = int(input())
rank = {"B" : 1, "S" : 2, "G":3 , "P":4, "D":5}
arr = list(input().split())
#딕셔너리로 첫번째 랭크순으로 1차 정렬, 그 이후 원소배열을 정수화시키고 값의 반대로 정렬
arr_answer = sorted(arr, key = lambda x: [rank[x[0]],-int(x[1:])])
ans = []
for i in range(n):
    if arr[i] != arr_answer[i]:
        ans.append(arr_answer[i])
if len(ans) == 0:
    print("OK")
else:
    print("KO\n"+" ".join(str(x) for x in ans))
