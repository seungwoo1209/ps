import math

def solution(fees, records):
    answer = []
    tmp = {}
    for r in records:
        t, num, inout = r.split()
        if num in tmp:
            tmp[num].append((t,inout))
        else:
            tmp[num] = [(t,inout)]
            
    def calc(prev, t):
        h1, m1 = map(int, prev.split(":"))
        h2, m2 = map(int, t.split(":"))
        return 60*(h2-h1) + (m2-m1)
    
    fee_list = []
    for key,value in tmp.items():
        prev = ""
        curr_sum = 0
        for v in value:
            t, inout = v
            if inout == "IN":
                prev = t
            if inout == "OUT": # prev와 t와의 차이 계산
                curr_sum += calc(prev, t)
                prev = "" # prev 초기화하기 => 마지막에 in만 있는 상황 감지를 위함
                
        if prev: # 마지막이 in이었고 out이 없었던 상태
            curr_sum += calc(prev, "23:59")
        
        # 요금 계산
        tot_price = fees[1]
        if curr_sum > fees[0]: # 기본 요금 제외 추가금
            tot_price += math.ceil((curr_sum - fees[0]) / fees[2]) * fees[3]
        fee_list.append((int(key), tot_price))
    
    fee_list.sort(key=lambda x: x[0])
    for each in fee_list:
        answer.append(each[1])
    
    return answer