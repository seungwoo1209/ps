def solution(people, limit):
    people.sort()
    answer = 0
    i,j=0,len(people)-1
    while i <= j:
        if people[i] + people[j] > limit:
            j -= 1 # j만 태워 보내
        else:
            i += 1
            j -= 1
        answer += 1
    
    
    return answer