'''
N * M 크기의 얼음 틀이 있다. 구멍이 뚫려 있는 부분은 0, 칸막이가 존재하는 부분은 1로 
표시된다. 구멍이 뚫려 있는 부분끼리 상, 하, 좌, 우로 붙어있는 경우 서로 연결되어있는 것으로 간주한다. 이때 얼음 틀의 모양이 주어졌을 떄 생성되는 총 아이스크림의 개수를 구하는 프로그램을 작성하시오. 다음의 4 * 5 얼음틀 예시에서는 아이스크림이 총 3개 생성된다.

입력조건
- 첫 번째 줄에 얼음 틀의 세로길이 N과 가로 길이 M이 주어진다.(1 <= N, M <= 1000)
- 두 번째 줄부터 N + 1번째 줄 까지 얼음 틀의 형태가 주어진다.
- 이때 구멍이 뚫려 있는 부분은 0, 그렇지 않은 부분은 1이다.

출력조건
- 한 번에 만들수 있는 아이스크림의 개수를 출력한다.
'''

  
#dfs를 통해 방문을 확인해서 방문한 곳에 벽을 세운다. 방문하지 않은 곳에서 확인을 시작했을 경우 +1
def dfs(n, m, x, y):
    #맵 범위를 넘어갈 경우 취소
    if x<=-1 or x>=n or y<=-1 or y >= m:
        return False
    #방문하지 않은 장소일 경우 검색 실시하고 True 반환
    if graph[x][y] == 0:
        graph[x][y] = 1
        dfs(n, m, x+1, y)
        dfs(n, m, x-1, y)
        dfs(n, m, x, y+1)
        dfs(n, m, x, y-1)
        return True
    return False
  
n , m = map(int,input().split())
graph = [list(map(int, input())) for _ in range(n)]

count = 0
for i in range(n):
    for j in range(m):
        if dfs(n, m, i, j):
            count += 1

print(count)

#어색하지만 bfs로도 구현이 가능하다
from collections import deque
def bfs(n, m, x, y):
    if graph[x][y] == 1:
        return False
    q = deque([[x, y]])
    while q:
        x, y = q.popleft()
        if x<=-1 or x>=n or y<=-1 or y >= m:
            continue
        if graph[x][y] == 0:
            graph[x][y] = 1
            q.append([x+1,y])
            q.append([x-1,y])
            q.append([x,y+1])
            q.append([x,y-1])
    return True

n , m = map(int,input().split())
graph = [list(map(int, input())) for _ in range(n)]

count = 0
for i in range(n):
    for j in range(m):
        if bfs(n, m ,i, j):
            count += 1
        

print(count)
