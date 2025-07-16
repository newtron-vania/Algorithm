import sys
input = sys.stdin.readline
from itertools import combinations
import heapq


import sys
n = int(sys.stdin.readline())
dp = [0]*(n+1)
backtracking = [n]
for i in range(2, n+1):
    dp[i] = dp[i-1]+1
    if not i%2:
        dp[i] = min(dp[i], dp[i//2]+1)
    if not i%3:
        dp[i] = min(dp[i],dp[i//3]+1)
t = n
while t > 1:
    k = t-1
    if t%2 == 0:
        if dp[k] > dp[t//2]:
            k = t//2
    if t%3 == 0:
        if dp[k] > dp[t//3]:
            k = t//3
    backtracking.append(k)
    t = k
        
        
print(dp[n])
print(*backtracking)