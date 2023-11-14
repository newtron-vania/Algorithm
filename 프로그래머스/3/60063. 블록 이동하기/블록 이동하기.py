import sys
import itertools
from collections import deque
input = sys.stdin.readline

from collections import deque

def solution(board):
    #미로 크기
    n = len(board)
    answer = 0
    #방향
    dir = ((0,1),(1,0),(-1,0),(0,-1))
    #회전 방향
    rot = {0:[(0,0),(0,0), (0,1), (-1,0), (-1,1)], 1:[(0,0),(0,0),(1,0),(0,-1),(1,-1)]}
    
    #가로 : 0, 세로 : 1, 기준 : 두 좌표 중 더 작은 좌표
    visited = [[[0, 0] for _ in range(n)] for _ in range(n)]
    #count, x, y, dir
    objPos = (0,0,0,0)
    queue = deque([objPos])
    while queue:
        count, x1, y1, d = queue.popleft()
        #기준 좌표를 통해 두 번째 좌표 출력
        x2, y2 = x1 + dir[d][0], y1 + dir[d][1]
        #두 좌표 중 한 곳이 목적지에 도달하면 종료
        if (x1 == n-1 and y1 == n-1) or (x2 == n-1 and y2 == n-1):
            answer = count
            break
        for nx, ny in dir:
            #해당 방향으로 이동할 수 있는지 확인
            hx1, hy1, hx2, hy2 = x1 + nx, y1 + ny, x2 + nx, y2 + ny
            if 0<=hx1<n and 0<=hy1<n and 0<=hx2<n and 0<=hy2<n:
                if board[hx1][hy1] == 0 and board[hx2][hy2] == 0:
                    #회전X의 경우 : 이동 방향에 벽이 없고 현재 회전방향 상태로 방문한 적이 없다면 추가
                    if visited[hx1][hy1][d] == 0:
                        visited[hx1][hy1][d] = 1
                        queue.append((count+1, hx1, hy1, d))
                    #회전O의 경우
                    #가로방향이고 세로축 이동이고 그 방향에 벽이 없다면 해당 방향으로 회전하고 방문 확인
                    if nx != 0 and d == 0:
                        #nx>0 : 1, 2 | nx <0 : -1, -2
                        nd = 1
                        for i in range(1,3):
                            hx, hy = x1 + rot[d][i*nx][0], y1 + rot[d][i*nx][1]
                            if visited[hx][hy][nd] == 0:
                                visited[hx][hy][nd] = 1
                                queue.append((count+1, hx, hy, nd))
                    #세로방향이고 가로축 이동이고 그 방향에 벽이 없다면 해당 방향으로 회전하고 방문 확인
                    elif ny != 0 and d == 1:
                        nd = 0
                        for i in range(1,3):
                            hx, hy = x1 + rot[d][i*ny][0], y1 + rot[d][i*ny][1]
                            if visited[hx][hy][nd] == 0:
                                visited[hx][hy][nd] = 1
                                queue.append((count+1, hx, hy, nd))
    return answer

