

n = int(input())
arr = [0]
for _ in range(n):
    arr.append(int(input()))
isError = False
dp = [0] * (n+1)
title_idx = [0] * (n+1)
for idx, level in enumerate(arr[:-1]):
    if level+1 < arr[idx+1]:
        isError = True
        break
    title_idx[level] = idx
    dp[title_idx[level-1]] += 1
if isError:
    print(-1)
else:
    print(*dp[1:], sep = "\n")
