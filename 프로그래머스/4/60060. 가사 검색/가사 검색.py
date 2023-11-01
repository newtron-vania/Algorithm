from bisect import bisect_left, bisect_right

array=[[] for _ in range(10001)]
reverse_array=[[] for _ in range(10001)]
def solution(words, queries):
    answer = []


    for word in words:
        array[len(word)].append(word)
        reverse_array[len(word)].append(word[::-1])
    
    for _ in range(10001):
        array[_].sort()
        reverse_array[_].sort()
    
    for query in queries:
        if query[0] == '?' and query[-1] == '?':
            answer.append(len(array[len(query)]))
            continue
        elif query[0]=='?':
            lindex=bisect_left(reverse_array[len(query)], query[::-1].replace('?','a'))
            rindex=bisect_right(reverse_array[len(query)], query[::-1].replace('?','z'))
        else:
            lindex=bisect_left(array[len(query)], query.replace('?','a'))
            rindex=bisect_right(array[len(query)], query.replace('?','z'))
        answer.append(rindex-lindex)
        
    return answer