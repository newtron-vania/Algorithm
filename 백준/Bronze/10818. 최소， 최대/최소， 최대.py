import sys
N = int(sys.stdin.readline())
list = [int(i) for i in sys.stdin.readline().split()]
print(min(list), max(list))