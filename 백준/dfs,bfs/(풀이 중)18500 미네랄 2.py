'''
문제
창영과 상근은 한 동굴을 놓고 소유권을 주장하고 있다. 두 사람은 막대기를 서로에게 던지는 방법을 이용해 누구의 소유인지를 결정하기로 했다. 싸움은 동굴에서 벌어진다. 동굴에는 미네랄이 저장되어 있으며, 던진 막대기가 미네랄을 파괴할 수도 있다.

동굴은 R행 C열로 나타낼 수 있으며, R×C칸으로 이루어져 있다. 각 칸은 비어있거나 미네랄을 포함하고 있으며, 네 방향 중 하나로 인접한 미네랄이 포함된 두 칸은 같은 클러스터이다.

창영은 동굴의 왼쪽에 서있고, 상근은 오른쪽에 서있다. 두 사람은 턴을 번갈아가며 막대기를 던진다. 막대를 던지기 전에 던질 높이를 정해야 한다. 막대는 땅과 수평을 이루며 날아간다.

막대가 날아가다가 미네랄을 만나면, 그 칸에 있는 미네랄은 모두 파괴되고 막대는 그 자리에서 이동을 멈춘다.

미네랄이 파괴된 이후에 남은 클러스터가 분리될 수도 있다. 새롭게 생성된 클러스터가 떠 있는 경우에는 중력에 의해서 바닥으로 떨어지게 된다. 떨어지는 동안 클러스터의 모양은 변하지 않는다. 클러스터는 다른 클러스터나 땅을 만나기 전까지 게속해서 떨어진다. 클러스터는 다른 클러스터 위에 떨어질 수 있고, 그 이후에는 합쳐지게 된다.

동굴에 있는 미네랄의 모양과 두 사람이 던진 막대의 높이가 주어진다. 모든 막대를 던지고 난 이후에 미네랄 모양을 구하는 프로그램을 작성하시오.
=============================
입력
첫째 줄에 동굴의 크기 R과 C가 주어진다. (1 ≤ R,C ≤ 100)

다음 R개 줄에는 C개의 문자가 주어지며, '.'는 빈 칸, 'x'는 미네랄을 나타낸다.

다음 줄에는 막대를 던진 횟수 N이 주어진다. (1 ≤ N ≤ 100)

마지막 줄에는 막대를 던진 높이가 주어지며, 공백으로 구분되어져 있다. 모든 높이는 1과 R사이이며, 높이 1은 행렬의 가장 바닥, R은 가장 위를 의미한다. 첫 번째 막대는 왼쪽에서 오른쪽으로 던졌으며, 두 번째는 오른쪽에서 왼쪽으로, 이와 같은 식으로 번갈아가며 던진다.

공중에 떠 있는 미네랄 클러스터는 없으며, 두 개 또는 그 이상의 클러스터가 동시에 떨어지는 경우도 없다.
=============================
출력
입력 형식과 같은 형식으로 미네랄 모양을 출력한다.

출처 - https://www.acmicpc.net/problem/18500
'''
#미네랄이 파괴되었을 때 bfs를 이용해서 분리된 클러스터를 찾아내고, 최소 수직낙하거리를 찾아내서 그만큼 클러스터를 옮겨야 한다. 미네랄 1과는 달리 같은 행의 클러스터의 사이에 미네랄이 존재하는 경우도 확인하여 수직낙하거리를 찾아낸다.

from collections import deque
def check_mineral(x, y, graph):
    #북, 남, 서, 동쪽 미네랄 확인
    dir = [[-1,0], [1, 0], [0, -1], [0, 1], [1, 0]]
    N, M = len(graph), len(graph[0])
    visited = [[0]*M for _ in range(N+1)]
    visited[x][y] = 1
    for mx, my in dir:
        hx, hy = x + mx, y + my
        if hx <= 0 or hy < 0 or hx >= N or hy >= M:
            continue
        if graph[hx][hy] == "x" and visited[hx][hy] == 0:
            visited[hx][hy] = 1
            gravity_check = bfs(hx, hy, graph, visited)
            if gravity_check:
                return True
    return False
 
 
def bfs(x, y, graph, visited):
    queue = deque()
    queue.append([x,y])
    N, M = len(graph), len(graph[0])
    dir = [[-1,0], [0, -1], [0, 1], [1, 0]]
    #바닥이랑 붙어있는지 확인
    is_bottom = False
    #idx = 순서, 내부 idx = 미네랄 높이
    cluster = [[] for _ in range(M)]
    cluster[y].append(x)
    while queue:
        x, y = queue.popleft()
        for mx, my in dir:
            hx, hy = x + mx, y + my
            if hx < 0 or hy < 0 or hx >= N or hy >= M:
                continue
            if graph[hx][hy] == "x" and visited[hx][hy] == 0:
                if hx == 0:
                    is_bottom = True
                cluster[hy].append(hx)
                queue.append([hx, hy])
                visited[hx][hy] = 1
    #바닥과 연결되어 있다면 중지
    if is_bottom:
        return False
    for idx, val in enumerate(cluster):
        for i in val:
            graph[i][idx] = "."
    #최소 수직 길이 찾기
    min_height = 1e9
    for idx1, minerals in enumerate(cluster):
        if len(minerals) == 0:
    	      continue
        minerals.sort()
        for idx2, val in enumerate(minerals):
            if idx2 == 0:
                end = -1
            else :
                end = minerals[idx2-1]
            for i in range(val-1, end, -1):
                if graph[i][idx1] == "x":
                    min_height = min(min_height, val - i-1)
    #최소 수직길이만큼 클러스터 이동
    for idx, val in enumerate(cluster):
        for i in val:
            graph[i-min_height][idx] = "x"
    return True
 
 
 
N, M = map(int,input().split())
#시작 좌표를 1로 맞추고, 아래에 X가 존재할 경우 떨어지는 것을 멈추게 하기 위해 바닥에 미네랄이 있다고 가정한다.
graph = [list(input().strip()) for _ in range(N)] + ["x"*M]
graph.reverse()
count = int(input())
#막대를 던지는 방향
dy = [1,0]
heights = list(map(int, input().split()))

for i in range(count):
    h = heights[i]
    if dy[i%2]:
        for j in range(M):
            if graph[h][j] == "x":
                graph[h][j] = "."
                check_mineral(h,j, graph)
                break
    else:
        for j in range(M-1, -1, -1):
            if graph[h][j] == "x":
                graph[h][j] = "."
                check_mineral(h,j, graph)
                break
 
for i in reversed(graph[1:]):
	print(*i, sep="")
