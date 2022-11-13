'''
문제
N(1 ≤ N ≤ 100,000)개의 로프가 있다. 이 로프를 이용하여 이런 저런 물체를 들어올릴 수 있다. 각각의 로프는 그 굵기나 길이가 다르기 때문에 들 수 있는 물체의 중량이 서로 다를 수도 있다.

하지만 여러 개의 로프를 병렬로 연결하면 각각의 로프에 걸리는 중량을 나눌 수 있다. k개의 로프를 사용하여 중량이 w인 물체를 들어올릴 때, 각각의 로프에는 모두 고르게 w/k 만큼의 중량이 걸리게 된다.

각 로프들에 대한 정보가 주어졌을 때, 이 로프들을 이용하여 들어올릴 수 있는 물체의 최대 중량을 구해내는 프로그램을 작성하시오. 모든 로프를 사용해야 할 필요는 없으며, 임의로 몇 개의 로프를 골라서 사용해도 된다.


입력
첫째 줄에 정수 N이 주어진다. 다음 N개의 줄에는 각 로프가 버틸 수 있는 최대 중량이 주어진다. 이 값은 10,000을 넘지 않는 자연수이다.

출력
첫째 줄에 답을 출력한다.
'''


from collections import deque
n = int(input())
lopes = []
for _ in range(n):
    lopes.append(int(input()))
q = deque(sorted(lopes))
result = 0
l = len(q)
while q:
    v = q.popleft() * l
    if result < v:
        result = v
    l -= 1

print(result)

#더 줄일 수 있는 방법이 있을까? 같은 값의 경우 반복을 띄어넘는다던가...

#dictionary를 이용해보니 메모리는 줄어들었으니 시간은 오히려 늘어났다.
from collections import defaultdict
n = int(input())
current_count = n
lope_count = {}
ans = 0
for _ in range(n):
    k = int(input())
    if k in lope_count:
        lope_count[k] += 1
    else:
        lope_count[k] = 1
lope_count = dict(sorted(lope_count.items()))
for key, val in lope_count.items():
    v = key*current_count
    if ans < v:
        ans = v
    current_count -= val
    
print(ans)
