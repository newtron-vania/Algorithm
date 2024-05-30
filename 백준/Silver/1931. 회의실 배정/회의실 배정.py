import sys
n = int(sys.stdin.readline())
cur = []
ans = []
for _ in range(n):
    cur.append(list(map(int, sys.stdin.readline().split())))

cur.sort(key=lambda x:(x[1], x[0]))

last=0
for k in cur:
    if last<=k[0]:
        last=k[1]
        ans.append(k)
print(len(ans))
        