'''
문제
상근이는 어렸을 적에 "봄보니 (Bomboni)" 게임을 즐겨했다.

가장 처음에 N×N크기에 사탕을 채워 놓는다. 사탕의 색은 모두 같지 않을 수도 있다. 상근이는 사탕의 색이 다른 인접한 두 칸을 고른다. 그 다음 고른 칸에 들어있는 사탕을 서로 교환한다. 이제, 모두 같은 색으로 이루어져 있는 가장 긴 연속 부분(행 또는 열)을 고른 다음 그 사탕을 모두 먹는다.

사탕이 채워진 상태가 주어졌을 때, 상근이가 먹을 수 있는 사탕의 최대 개수를 구하는 프로그램을 작성하시오.
=================================================
입력
첫째 줄에 보드의 크기 N이 주어진다. (3 ≤ N ≤ 50)

다음 N개 줄에는 보드에 채워져 있는 사탕의 색상이 주어진다. 빨간색은 C, 파란색은 P, 초록색은 Z, 노란색은 Y로 주어진다.

사탕의 색이 다른 인접한 두 칸이 존재하는 입력만 주어진다.

출력
첫째 줄에 상근이가 먹을 수 있는 사탕의 최대 개수를 출력한다.
=================================================
반례들
https://www.acmicpc.net/board/view/58247
'''




'''
풀이과정
실수만 하지 않는다면 구현하는데 별로 큰 어려움은 없는 문제이다.
좌표에서 인접한 서, 북을 비교하지 않은 이유는 이전 좌표에서 동, 남을 비교하고 swap을 실시하였기 때문에 이전과 중복된 형태의 그래프를 다시 확인하는 형태가 되기 때문이다.
다만, swap시 현재 좌표와 swap한 좌표 두 경우 둘 다 확인하는 걸 잊지 않아야 한다.
'''

def check_cnt(x, y, arr):
    max_count = 0
    w_result = 1
    h_result = 1
    for i in range(n-1):
        if arr[x][i] != arr[x][i+1]:
            w_result = 1
        else:
            w_result += 1
            max_count = max(max_count,w_result)
        if arr[i][y] != arr[i+1][y]:
            h_result = 1
        else:
            h_result += 1
            max_count = max(max_count,h_result)
    return max_count
    
    

n = int(input())

arr = [list(input().strip()) for _ in range(n)]
#비교할 방향
dx = [1, 0]
dy = [0, 1]
ans = 0
for x in range(n):
    for y in range(n):
        for k in range(2):
            hx, hy = x+dx[k], y+dy[k]
            #그래프 범위에서 벗어날 시 pass
            if hx<0 or hy<0 or hx>=n or hy>=n:
                continue
            #swap후 두 좌표에서 행,열을 확인한다. 
            if arr[hx][hy] != arr[x][y]:
                arr[hx][hy], arr[x][y] = arr[x][y], arr[hx][hy]
                ans = max(ans, check_cnt(x, y, arr))
                ans = max(ans, check_cnt(hx, hy, arr))
                arr[hx][hy], arr[x][y] = arr[x][y], arr[hx][hy]
            else:
                ans = max(ans, check_cnt(x, y, arr))
print(ans)
          
