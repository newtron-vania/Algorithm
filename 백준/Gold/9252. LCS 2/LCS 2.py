import sys
input = sys.stdin.readline
import heapq

from collections import deque

A = input().strip()
B = input().strip()
n = len(A)
m = len(B)

dp = [[0]*(m+1) for _ in range(n+1)]

for x in range(1,n+1):
    for y in range(1,m+1):
        if A[x-1] == B[y-1]:
            dp[x][y] = dp[x-1][y-1] + 1
        else:
            dp[x][y] = max(dp[x][y-1], dp[x-1][y])

word = ""
while dp[n][m] > 0:
    if dp[n-1][m] == dp[n][m]:
        n = n-1
    elif dp[n][m-1] == dp[n][m]:
        m = m-1
    else:
        n = n-1
        m = m-1
        word = A[n] + word
print(dp[-1][-1])
print(word)





