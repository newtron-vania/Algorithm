import sys
con = sys.stdin.readline().strip().split("-")
for i in range(len(con)):
    con[i] = sum(list(map(int, con[i].split("+"))))
print(con[0] - sum(con[1:]))