'''
문제
N×M크기의 배열로 표현되는 미로가 있다.

1	0	1	1	1	1
1	0	1	0	1	0
1	0	1	0	1	1
1	1	1	0	1	1
미로에서 1은 이동할 수 있는 칸을 나타내고, 0은 이동할 수 없는 칸을 나타낸다. 이러한 미로가 주어졌을 때, (1, 1)에서 출발하여 (N, M)의 위치로 이동할 때 지나야 하는 최소의 칸 수를 구하는 프로그램을 작성하시오. 한 칸에서 다른 칸으로 이동할 때, 서로 인접한 칸으로만 이동할 수 있다.

위의 예에서는 15칸을 지나야 (N, M)의 위치로 이동할 수 있다. 칸을 셀 때에는 시작 위치와 도착 위치도 포함한다.

입력
첫째 줄에 두 정수 N, M(2 ≤ N, M ≤ 100)이 주어진다. 다음 N개의 줄에는 M개의 정수로 미로가 주어진다. 각각의 수들은 붙어서 입력으로 주어진다.

출력
첫째 줄에 지나야 하는 최소의 칸 수를 출력한다. 항상 도착위치로 이동할 수 있는 경우만 입력으로 주어진다.

예제 입력 1   예제 출력 1 
4 6           15
101111
101010
101011
111011

예제 입력 2   예제 출력 2 
4 6           9
110110
110110
111111
111101

예제 입력 3                 예제 출력 3 
2 25                        38
1011101110111011101110111
1110111011101110111011101

예제 입력 4   예제 출력 4 
7 7           13
1011111
1110001
1000001
1000001
1000001
1000001
1111111
'''

#bfs를 통해 이동 구간으로 이동한 동안의 거리 중 최소값을 저장하면서 마지막 구간까지의 거리의 최소값을 찾아낸다.

from collections import deque
def bfs(n, m, graph):
    n , m = n-1, m-1
    dx = [-1, 0, 1, 0]
    dy = [0, 1, 0, -1]
    q = deque()
    q.append((0,0))
    while q:
        x, y = q.popleft()
        print(x, y)
        if x == n and y == m:
            return graph[x][y]
        for i in range(4):
            hx, hy = x + dx[i] , y + dy[i]
            if hx<0 or hy < 0 or hx > n or hy > m:
                continue
            if graph[hx][hy] == 0:
                continue
            elif graph[hx][hy] == 1:
                q.append((hx, hy))
                graph[hx][hy] = graph[x][y] + 1
        for k in graph:
        	print(*k)
    return -1
 
n, m = map(int, input().split())
graph = [list(map(int, input())) for _ in range(n)]
 
print(bfs(n, m, graph))
