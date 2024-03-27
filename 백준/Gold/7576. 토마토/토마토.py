from collections import deque
#BFS를 이용한 문제
m, n = map(int, input().split())
graph = []
tomatoes = deque()
queue = deque()
for i in range(n):
    arr = list(map(int, input().split()))
    graph.append(arr)
    for j in range(m):
        if arr[j] == 1:
            tomatoes.append((i,j))
#방향
dir = [(1,0),(0,1),(-1,0),(0,-1)]
day = 0
#큐에 현재일자 토마토 삽입
#BFS 실시
while True:
    #익은 토마토를 큐에 삽입
    queue.extend(tomatoes)
    tomatoes.clear()
    #오늘이 다 끝날때까지
    while queue:
        x, y = queue.popleft()
        for i in range(4):
            hx, hy = x + dir[i][0], y + dir[i][1]
            if hx<0 or hy<0 or hx>=n or hy>=m:
                continue
            elif graph[hx][hy] == 0:
                graph[hx][hy] = 1
                tomatoes.append((hx,hy))
    #오늘 익은 토마토가 있는지 확인
    if len(tomatoes) == 0:
        break
    day += 1
possible = True
for i in graph:
    if i.count(0):
        possible = False
        break
if possible:
    print(day)
else:
    print(-1)