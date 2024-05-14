import sys
input = sys.stdin.readline


def dfs(cnt, x,y):
    global answer
    answer = max(answer, cnt)
    for i in range(4):
        hx, hy = x + dir[i][0], y + dir[i][1]
        if hx<0 or hy<0 or hx>=n or hy>=m:
            continue
        if graph[hx][hy] in alpha:
            continue
        alpha.add(graph[hx][hy])
        dfs(cnt+1, hx, hy)
        alpha.remove(graph[hx][hy])


alpha = set()
n, m = map(int, input().split())
graph = [list(input().strip()) for _ in range(n)]
dir = ((-1,0),(1,0),(0,-1),(0,1))
alpha.add(graph[0][0])
answer = 0
dfs(1, 0, 0)
print(answer)
    
