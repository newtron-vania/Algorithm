def rotate(key):
    n = len(key)
    result = [[0]*n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            x, y =  j, n-i-1
            result[x][y] = key[i][j]
    return result

def check_open(key, lock, n, m, count):
    for x in range(m + n-1):
        for y in range(m + n-1):
            OK = True
            result = 0

            #n의 범위 안에서 하되, 자물쇠에 포함되지 않는 부분은 반복문을 실행하지 않는다.
            for i in range(n):
                for j in range(n):
                    hx = x-(n-1-i)
                    hy = y-(n-1-j)
                    if hx < 0 or hy < 0 or hx >=m or hy >= m: continue
                    if key[i][j] == 1 and lock[hx][hy] == 1:
                        OK = False
                        break
                    elif key[i][j] == 1 and lock[hx][hy] == 0:
                        result += 1
                if not OK:
                    break
            if OK and result == count:
                return True
    return False
    
    
def solution(key, lock):
    holl_count = 0
    n, m = len(key), len(lock)
    for l in lock:
        holl_count += l.count(0)

    answer = False
    for i in range(4):
        answer = check_open(key,lock,n,m, holl_count)
        if answer:
            break
        key = rotate(key)
    
    return answer