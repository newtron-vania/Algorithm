def solution(N, stages):
    lived = [0]*(N+1)
    for stage in stages:
        lived[stage-1] += 1
    success = lived[:]
    print(lived)

    for i in range(N,0, -1):
        success[i-1] += success[i]
    failed = [[x,0] for x in range(1,N+1)]
    for i in range(N):
        if success[i] == 0:
            continue
        failed[i][1] = lived[i] / success[i]
    failed.sort(key =lambda x : [-x[1], x[0]])
    answer = [x[0] for x in failed]
    return answer