def dfs(word):
    if word == "":
        return ""
    left = 0
    right = 0
    isCorrect = False
    if word[0] == "(":
        isCorrect = True
        left += 1
    else:
        isCorrect = False
        right += 1
    i = 1
    while left != right:
        if word[i] == "(":
            left += 1
        else:
            right += 1
        i += 1
    u = word[:i]
    v = word[i:]
    print("올바른 문자열 : ",isCorrect)
    print("u : ", u, "v : ", v)
    v = dfs(v)
    print("dfs 실행 결과 - u : ", u, "v : ", v)
    if isCorrect:
        answer = u + v
    else:
        answer = "(" + v + ")"
        for w in range(1, len(u)-1):
            if u[w] == "(":
                answer += ")"
            else:
                answer  += "("
    return answer

def solution(p):
    
    answer = dfs(p)
    return answer