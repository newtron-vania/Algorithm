import sys
input = sys.stdin.readline
from collections import deque
import heapq

#세그먼트 트리 생성
def init(start, end, node):
    #범위가 1일 경우
    if start == end: 
        segment_tree[node] = (arr[start], arr[end])
        return segment_tree[node]
    #범위가 2 이상일 경우
    mid = (start+end)//2
    l = init(start, mid, node*2)
    r = init(mid+1, end, node*2+1)

    segment_tree[node] = (min(l[0], r[0]), max(l[1], r[1])) 
    return segment_tree[node]
 
def find(start, end, node, left, right):
    if left > end or right < start:
        return (MAX, 0)
    elif start >= left and end <= right:
        return segment_tree[node]

    mid = mid = (start+end)//2
    l = find(start, mid, node*2, left, right)
    r = find(mid+1, end, node*2 +1, left, right)
    return (min(l[0], r[0]), max(l[1], r[1]))

 

MAX = sys.maxsize;
n, m = map(int, input().split())
arr = [int(input()) for _ in range(n)]
segment_tree = [0] *(n*4)

start = 0
end = n-1
init(start, end, 1)
answer = []
for _ in range(m):
    a, b = map(int, input().split())
    answer.append(find(start, end, 1, a-1, b-1))

for ans in answer:
    print(*ans)