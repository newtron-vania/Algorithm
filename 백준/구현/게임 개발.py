'''
이것이 코딩테스트다. 118p



해결 과정 : 
x와 y의 값을 따로 저장하고, 회전 후 이동 이후의 위치의 값을 계속 확인하면서 조건문을 걸어주는 게 핵심이었다.
'''

def turn_left(dir):
    dir -= 1
    if dir <0 :
        dir = 3
    return dir
n, m = map(int,input().split())
x, y, dir = map(int, input().split())
m = [list(map(int,input().split())) for _ in range(n)]

m[x][y] = 2
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]
ans = 1
turn_time = 0 

while True:
    dir = turn_left(dir)
    nx = x + dx[dir]
    ny = y + dy[dir]
    if m[nx][ny] == 0:
        x = nx
        y = ny
        m[nx][ny] = 2
        ans += 1
        turn_time = 0
        continue
    else:
      turn_time += 1
    if turn_time == 4:
        x += dx[dir-2]
        y += dy[dir-2]
        if m[x][y] == 1:
          break
        turn_time = 0
print(ans)
