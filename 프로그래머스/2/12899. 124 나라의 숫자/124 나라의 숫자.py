def solution(n):
    num_change={0:"1",1:"2",2:"4"}
    answer = ''
    while n>0:
        n-=1
        answer = num_change[n%3] + answer
        n//=3
    
        
    return answer