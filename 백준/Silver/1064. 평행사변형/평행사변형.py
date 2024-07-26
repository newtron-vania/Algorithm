import sys
input = sys.stdin.readline
import math

def solve(xa, ya, xb, yb, xc, yc):
    if ((xa - xb) * (ya - yc) == (ya - yb) * (xa - xc)):  # 직선 ab와 직선 ac가 평행 또는 일치할 때
        return -1.0

    ab = math.sqrt((xa - xb) ** 2 + (ya - yb) ** 2)
    ac = math.sqrt((xa - xc) ** 2 + (ya - yc) ** 2)
    bc = math.sqrt((xb - xc) ** 2 + (yb - yc) ** 2)
    l = [ab+ac, ab+bc, ac+bc]
    result = max(l)-min(l)
    return 2*result
if __name__ == "__main__":
    xa, ya, xb, yb, xc, yc = map(int, input().split())
    answer = solve(xa, ya, xb, yb, xc, yc)
    print(answer)