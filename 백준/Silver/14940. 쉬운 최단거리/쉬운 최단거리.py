import sys
from collections import deque

def adj(row,col):
    return [(row+1, col), (row-1, col), (row, col+1), (row, col-1)]


def bfs(row, col, curr_depth):
    global arr, result, dq, visited
    if visited[row][col]:
        return
    else:
        visited[row][col] = True
        result[row][col] = curr_depth

    for (i,j) in adj(row,col):
        if 0<= i <= N-1 and 0 <= j <= M-1 and not visited[i][j] and arr[i][j] == 1:
            dq.append((i,j,curr_depth+1))

N, M = map(int, sys.stdin.readline().split())

arr = []
for _ in range(N):
    arr.append(list(map(int, sys.stdin.readline().split())))

result = []
for i in range(N):
    result.append([])
    for j in range(M):
        result[i].append(2001)

visited = []
for i in range(N):
    visited.append([])
    for j in range(M):
        visited[i].append(False)

dq = deque()

for i in range(N):
    for j in range(M):
        if arr[i][j] == 2:
            dq.append((i, j, 0))


while dq:
    i, j, depth = dq.popleft()
    bfs(i, j, depth)

for i in range(N):
    for j in range(M):
        print(f"{0 if arr[i][j] == 0 else -1 if result[i][j] == 2001 else result[i][j]} ", end="")
    print()