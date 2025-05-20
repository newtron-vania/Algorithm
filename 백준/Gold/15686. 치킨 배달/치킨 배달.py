from itertools import combinations

n, m = map(int, input().split())

maps = [list(input().strip().split()) for _ in range(n)]
house_vec = []
chick_vec = []
result = int(1e10)
for i in range(n):
    for j in range(n):
        if maps[i][j] == "1":
            house_vec.append([i,j])
        elif maps[i][j] == "2":
            chick_vec.append([i,j])

for candidate in list(combinations(chick_vec, m)):
    all_dist = 0
    for idx, vec in enumerate(house_vec):
        dist = 10000
        for c in candidate:
            dist = min(dist, abs(c[0]-vec[0]) + abs(c[1]-vec[1]))
        all_dist += dist
    result = min(result, all_dist)
print(result)