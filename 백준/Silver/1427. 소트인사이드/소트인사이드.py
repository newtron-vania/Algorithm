import sys
n = sys.stdin.readline().strip()
numbers = [int(i) for i in n]
numbers=  sorted(numbers, reverse=True)
print("".join(str(_) for _ in numbers))