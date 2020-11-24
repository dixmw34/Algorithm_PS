def solution(arr):
    answer = []
    n = 0
    for i in arr:
        if(n == 0) :
            answer.append(i)
            n+=1
        elif (answer[n-1] != i):
            answer.append(i)
            n+=1
    
    return answer