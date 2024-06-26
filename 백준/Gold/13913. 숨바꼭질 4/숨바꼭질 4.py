import sys
input = sys.stdin.readline
import heapq

from collections import deque

def bfs(start, end):
    heap = []
    trace = [start]
    if start > end:
        for i in range(start-1, end-1, -1):
            trace.append(i)
        return start-end, trace
    heapq.heappush(heap, (0, start, trace))
    visited[start] = (0, start)
    
    while heap:
        time, now_dist, trace = heapq.heappop(heap)
        if now_dist == end:
            return time , trace
        for next_dist in [now_dist-1, now_dist+1, now_dist*2]:
            if next_dist > MAX*2 or next_dist < 0:
                continue
            if visited[next_dist] != -1:
                continue
            visited[next_dist] = time+1
            heapq.heappush(heap, (time+1, next_dist, trace + [next_dist]))

MAX = 100001
n, m = map(int,input().split())
visited = [-1]*(MAX*4)

time, trace =bfs(n, m)
print(time)
print(*trace)




