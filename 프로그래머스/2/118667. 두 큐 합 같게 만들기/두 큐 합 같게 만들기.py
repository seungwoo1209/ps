def solution(queue1, queue2):
    list = queue1 + queue2
    
    total_sum = 0
    for i in range(len(list)):
        total_sum += list[i]
    
    temp = 0
    res_i = []
    res_j = []
    
    start = 0
    sum = 0
    for end in range(0,len(list)):
        sum += list[end] # 0부터 i까지 리스트의 원소들을 계속 더해 나가기
        if sum < (total_sum / 2): # 현재 원소를 더했는데도 아직 sum이 반도 안 되면 다음꺼 더하러 가기
            pass
        elif sum == (total_sum / 2):
            # 현재 end는 배열의 인덱스를 나타냄. "여기까지 더한다" 의 경계선의 의미인 res_i에 추가할때 1 더해 주기
            res_i.append(end+1) 
            res_j.append(start)
        else: # 지금 합이 반보다 더 커?
            # 그럼 작아질때까지 앞에있는거 빼
            while sum > (total_sum / 2):
                sum -= list[start]
                start += 1
                # 빼다가 같아지면, 정답 후보에 추가
                if sum == (total_sum / 2):
                    res_i.append(end+1) 
                    res_j.append(start)
                    break
                    
    if len(res_i) == 0:
        return -1
    else:
        answer = float("inf")
        for k in range(len(res_i)):
            tmp = 0
            if res_i[k] < len(queue1):
                tmp = res_i[k] + (len(list) - len(queue1) - res_j[k])
            else:
                tmp = (res_i[k] - len(queue1)) + (res_j[k])
            if tmp < answer:
                answer = tmp
                
    return answer