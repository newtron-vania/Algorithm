import sys
input = sys.stdin.readline
from collections import deque
import heapq

#세그먼트 트리 생성
def init(start, end, node):
    if start == end:
        segment_tree[node] = arr[start]
        return segment_tree[node]

    mid = (start  + end)//2
    segment_tree[node] = min(init(start, mid, node*2), init(mid+1, end, node*2+1))
    return segment_tree[node]
 
def find(start, end, node, left, right):
    if left > end or right < start:
        return MAX
    elif left <= start and end <= right:
        return segment_tree[node]

    mid =  (start  + end)//2
    return min(find(start, mid, node*2, left, right), find(mid+1, end, node*2+1, left, right))

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
    answer.append(find(start+1, end+1, 1, a, b))

print(*answer, sep="\n")