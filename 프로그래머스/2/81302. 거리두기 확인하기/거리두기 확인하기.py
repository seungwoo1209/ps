def test(nx,ny,each_room):
    if 0 <= nx <= 4 and 0 <= ny <= 4:
        if each_room[nx][ny] == "P":
            return 1
        else:
            return 0
    else:
        return 0

def solve(each_room):
    # 가로로 연속
    for each_row in each_room:
        tmp = 0
        for i in each_row:
            if i == "P":
                tmp += 1
                if tmp == 2:
                    return 0 # 가로에서 끝
            else:
                tmp = 0
    # 세로로 연속
    prev = 0
    for each_row in each_room:
        curr = 0
        for idx, char in enumerate(each_row):
            if char == "P":
                curr += 2 ** idx
        if prev & curr != 0:
            return 0 # 세로에서 끝
        prev = curr # 검사 한단계 통과
        
    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]
    
    # 빈 테이블 상하좌우로 두명이상 붙어있음
    for row_idx, each_row in enumerate(each_room):
        for col_idx, char in enumerate(each_row):
            if char == "O":
                sum = 0
                for i in range(4):
                    nx = row_idx + dx[i]
                    ny = col_idx + dy[i]
                    sum += test(nx,ny,each_room)
                if sum >= 2:
                    return 0 # 탈락
    return 1 # 합격

def solution(places):
    answer = []
    for each_room in places:
        answer.append(solve(each_room))
        
    return answer