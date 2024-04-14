from collections import deque

def dfs(v, n, visited_dfs, matrix):
    visited_dfs[v] = 1
    print(v, end = " ")
    for i in range(1,n+1):
        if matrix[v][i] == 1 and visited_dfs[i] == 0:
            dfs(i, n, visited_dfs, matrix)

def bfs(v, n, visited_bfs, matrix):
    q = deque([v])
    visited_bfs[v] = 1
    while q:
        v = q.popleft()
        print(v, end = " ")
        for i in range(1, n+1):
            if matrix[v][i] == 1 and visited_bfs[i] == 0:
                q.append(i)
                visited_bfs[i] = 1

n, m, v = map(int, input().split())
matrix = [[0] * (n+1) for _ in range(n+1)]

visited_dfs = [0 for _ in range(n+1)]
visited_bfs = [0 for _ in range(n+1)]

for _ in range(m):
    a, b = map(int, input().split())
    matrix[a][b] = matrix[b][a] = 1

dfs(v, n, visited_dfs, matrix)
print()
bfs(v, n, visited_bfs, matrix)