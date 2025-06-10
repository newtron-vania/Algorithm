import sys
input = sys.stdin.readline

def binary_search(val):
    start = 0
    end = len(answer)-1

    while start <= end:
        mid = (start + end)//2
        #val은 더 작은 값과 더 큰 값 사이에서 더 큰값과 교체되어야 한다.
        if answer[mid] >= val:
            end = mid-1
        else:
            start = mid+1
    return start


n = int(input())
arr = list(map(int, input().split()))

answer = [arr[0]]

for i in range(1,n):
    if answer[-1] < arr[i]:
        answer.append(arr[i])
    else:
        result = binary_search(arr[i])
        answer[result] = arr[i]

print(len(answer))
        