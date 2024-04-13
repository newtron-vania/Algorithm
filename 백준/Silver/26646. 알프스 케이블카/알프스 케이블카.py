import sys
sys.setrecursionlimit(10**6)


n = int(input())

heights = list(map(int, input().split()))

sum = 0
for i in range(n-1):
    sum += (heights[i] + heights[i+1])**2 + (heights[i]-heights[i+1])**2 
print(sum)