opr = input().strip().split("-")
for idx, val in enumerate(opr):
    opr[idx] = sum(list(map(int,val.strip().split("+"))))
    print(opr[idx])
print(opr[0] - sum(opr[1:]))
