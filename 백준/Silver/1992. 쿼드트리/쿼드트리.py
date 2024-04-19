def dfs(n, x, y, graph):
    bit = graph[x][y]
    for i in range(x, x + n):
        for j in range(y, y + n):
            if bit != graph[i][j]:
                hx, hy = x + n//2 , y + n//2
                ans.append("(")
                dfs(n//2, x, y, graph)
                dfs(n//2, x, hy, graph)
                dfs(n//2, hx, y , graph)
                dfs(n//2, hx, hy, graph)
                ans.append(")")
                return
    ans.append(bit)
    return
 
n = int(input())
graph = [input().strip() for _ in range(n)]
ans = []
 
dfs(n, 0, 0, graph)
print("".join(ans))