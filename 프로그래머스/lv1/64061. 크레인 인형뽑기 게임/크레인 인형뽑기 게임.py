def solution(board, moves):
    bag = []
    answer=0
    for i in moves:
        i -=1
        for j in range(len(board)):
            if board[j][i]>0:
                bag.append(board[j][i])
                board[j][i]=0
                
                if len(bag)>1:
                    if bag[-2]==bag[-1]:
                        answer+=2
                        bag.pop()
                        bag.pop()
                break
        
    return answer