import sys

input = sys.stdin.readline

N, r, c = map(int, input().split())

ans = 0
tmp = 2 ** (N)
while N > 0:
    sector = int((tmp / 2) ** 2)
    if r >= tmp/2:
        ans += sector + sector
        r -= int(tmp / 2)
    if c >= tmp/2:
        ans += sector
        c -= int(tmp / 2)
    N -= 1
    tmp = 2 ** (N)

print(ans)