from itertools import permutations

def solution(k, dungeons):
    answer = 0
    
    # python의 itertools는 메모리에 다 로드하지 않고 다음꺼 주고 다음꺼 주고 그렇게 구현해놓음
    for sequence in permutations(dungeons, len(dungeons)):
        curr = k
        count = 0
        for dungeon in sequence:
            # print(dungeon)
            if dungeon[0] <= curr: # 갈수있음
                curr -= dungeon[1]
                # print(f"curr: {curr}")
                count += 1
        answer = max(answer, count)
                
    return answer