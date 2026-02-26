def solution(land):
    answer = 0
    # ans = [[0,0,0,0]] * 2
    ans = [[0,0,0,0], [0,0,0,0]]
    for i, val in enumerate(land):
        # print(ans)
        ans[i % 2][0] = max(ans[(i + 1) % 2][1], ans[(i + 1) % 2][2], ans[(i + 1) % 2][3]) + val[0]
        ans[i % 2][1] = max(ans[(i + 1) % 2][2], ans[(i + 1) % 2][3], ans[(i + 1) % 2][0]) + val[1]
        ans[i % 2][2] = max(ans[(i + 1) % 2][3], ans[(i + 1) % 2][0], ans[(i + 1) % 2][1]) + val[2]
        ans[i % 2][3] = max(ans[(i + 1) % 2][0], ans[(i + 1) % 2][1], ans[(i + 1) % 2][2]) + val[3]
        # print(ans)
    
    answer = max(ans[0] + ans[1])
    return answer