import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

def setCount(currentNode, counts):
    counts[currentNode] = 1
    for node in graph[currentNode]:
        if counts[node] == 0:
            setCount(node, counts)
            counts[currentNode] += counts[node]




n, root, q = map(int, input().split())
graph = [[] for _ in range(n+1)]
counts = [0 for _ in range(n+1)]

for _ in range(n-1):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

setCount(root, counts)
answer = []
for _ in range(q):
    a = int(input())
    answer.append(counts[a])

print(*answer, sep="\n")