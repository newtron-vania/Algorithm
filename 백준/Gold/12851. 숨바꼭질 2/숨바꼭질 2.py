import sys
import heapq
from collections import deque

input = sys.stdin.readline

MAX = 100001
n, m = map(int, input().split())
start, end = n, m

visited = [0] * (MAX + 1)
cnt = 0
heap = []

heapq.heappush(heap, (0, start))  # (거리, 위치) 형태로 저장
visited[start] = 1

while heap:
    now_time, now_pos = heapq.heappop(heap)
    
    if now_pos == end:
        cnt += 1
        continue
    
    for next_pos in [now_pos - 1, now_pos + 1, now_pos * 2]:
        if next_pos < 0 or next_pos >= MAX:
            continue
        
        if visited[next_pos] == 0 or visited[next_pos] == visited[now_pos] + 1:
            visited[next_pos] = visited[now_pos] + 1
            heapq.heappush(heap, (now_time + 1, next_pos))

print(visited[end] - 1)
print(cnt)
