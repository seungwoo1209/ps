from collections import deque
import sys

MAX = 100_000
N, K = map(int, sys.stdin.readline().split())
if N >= K:
    print(N - K)
    sys.exit(0)

visited = [False] * (MAX + 1)
dq = deque([(N, 0)])
visited[N] = True

while dq:
    x, t = dq.popleft()
    if x == K:
        print(t)
        break
    for nx in (x-1, x+1, x*2):
        if 0 <= nx <= MAX and not visited[nx]:
            visited[nx] = True
            dq.append((nx, t+1))
