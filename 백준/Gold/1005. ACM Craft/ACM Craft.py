import math
import sys
from collections import deque
input = sys.stdin.readline

def topologySort(arrival):

    queue = deque()
    for i in range(1, n+1):
        if inDegree[i] == 0:
            queue.append(i)
            dp[i] = costs[i-1]

    while queue:
        current_node = queue.popleft()
        if current_node == arrival:
            return
        for next in graph[current_node]:
            dp[next] = max(dp[next], dp[current_node] + costs[next-1])
            inDegree[next] -= 1
            if inDegree[next] == 0:
                queue.append(next)
    


T = int(input())

for _  in range(T):
    n, m = map(int, input().split())
    costs = list(map(int, input().split()))
    graph = [[] for _ in range(n+1)]
    inDegree = [0] *(n+1)
    dp = [0]*(n+1)

    for _ in range(m):
        a, b = map(int, input().split())
        graph[a].append(b)
        inDegree[b] += 1

    arrival = int(input())

    topologySort(arrival)
    print(dp[arrival])


