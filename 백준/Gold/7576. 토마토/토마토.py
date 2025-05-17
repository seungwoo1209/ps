import sys
from collections import deque

input = sys.stdin.readline

N, M = map(int, input().split())

arr = [list(map(int, input().split())) for _ in range(M)]

DIRS = [(-1,0),(1,0),(0,1),(0,-1)]

dq = deque()

for i in range(M):
    for j in range(N):
        if arr[i][j] == 1:
            dq.append((i, j))

step = 0

while True:
    # 완료? 0이 하나라도 있으면 완료는 아님
    if any(0 in row for row in arr):
        a = len(dq)
        while a:
            a -= 1
            r, c = dq.popleft()
            for dx, dy in DIRS:
                if 0 <= r+dx < M and 0 <= c+dy < N and arr[r + dx][c + dy] == 0:
                    arr[r + dx][c + dy] = 1
                    dq.append((r + dx, c + dy))

        step += 1

        # 비정상?
        if not dq:
            print("-1")
            break
    else:
        # 완료된 경우
        print(step)
        break


