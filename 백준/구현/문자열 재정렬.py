'''
문제
- 알파벳 대문자와 숫자(0~9)로만 구성된 문자열이 입력으로 주어집니다. 이때 모든 알파벳을 오름차순으로 정렬하여 이어서 출력한 뒤에, 그 위에 모든 숫자를 더한 값을 이어서 출력합니다.

 

입력 -> 출력

K1KA5CB7 -> ABCKK13

AJKDLSI412K4JSJ9D -> ADDIJJJKKLSS20
'''

from collections import deque
q = deque(input().strip())
ans = []
nums = 0
while q:
    result = q.popleft()
    if ord(result) in range(ord("A"), ord("Z")+1):
        ans.append(result)
    else:
        nums += int(result)
print(*sorted(ans), nums, sep="")
