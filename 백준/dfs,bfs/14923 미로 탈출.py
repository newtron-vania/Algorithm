'''
문제
홍익이는 사악한 마법사의 꾐에 속아 N x M 미로 (Hx, Hy) 위치에 떨어졌다. 다행히도 홍익이는 마법사가 만든 미로의 탈출 위치(Ex, Ey)를 알고 있다. 하지만 미로에는 곳곳에 마법사가 설치한 벽이 있어 홍익이가 탈출하기 어렵게 하고 있다.

홍익이는 마법사의 연구실에서 훔친 지팡이가 있어, 벽을 길로 만들 수 있다. 그렇지만, 안타깝게도 마법의 지팡이는 단 한 번만 사용할 수 있다.

이때, 홍익이를 도와 미로에서 탈출할 수 있는지 알아보고, 할 수 있다면 가장 빠른 경로의 거리 D는 얼마인지 알아보자.

인접한 칸으로 이동하는데 똑같은 시간이 들고, 벽을 부수는 데 시간이 걸리지 않는다.

입력

N M
Hx Hy
Ex Ey
N X M 행렬
================================
2 ≤ N ≤ 1000, 2 ≤ M ≤ 1000
1 ≤ Hx, Hy, Ex, Ey ≤ 1000
(Hx, Hy)≠ (Ex, Ey)
==================================
행렬은 0과 1로만 이루어져 있고, 0이 빈 칸, 1이 벽이다.

출력
D (탈출 할 수 없다면, -1을 출력한다.)
'''

#2206번 벽 부수고 이동하기의 연장선. 시작점과 출발지점을 지정하고 bfs를 돌리면 된다.

from collections import deque
def bfs(n, m, x, y, c, ex, ey, graph, cache):
    #배열의 크기에 맞춤
    n -= 1
    m -= 1
    x -= 1
    y -= 1
    ex -= 1
    ey -= 1

    dx = [-1, 0, 1, 0]
    dy = [0, 1, 0, -1]
    q = deque([(x,y,c)])
    while q:
        x, y, c = q.popleft()
        if x == ex and y == ey:
            return cache[x][y][c]
        for i in range(4):
            hx, hy = x + dx[i], y + dy[i]
            if hx < 0 or hy < 0 or hx > n or hy > m:
                continue
            if graph[hx][hy] == 1 and c == 0:
                q.append((hx, hy, 1))
                cache[hx][hy][1] = cache[x][y][0] +1
            elif graph[hx][hy] == 0 and cache[hx][hy][c] == 0:
                q.append((hx, hy, c))
                cache[hx][hy][c] = cache[x][y][c] + 1
        print(x, y, c)
        for k in cache:
            print(k, sep="  ")
    return -1

n, m = map(int, input().split())
hx, hy = map(int, input().split())
ex, ey = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(n)]
cache = [[[0 for _ in range(2)] for _ in range(m)] for _ in range(n)]

print(bfs(n, m, hx, hy, 0, ex, ey, graph, cache))
