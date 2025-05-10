import sys

input = sys.stdin.readline

N, K = map(int, input().split())

money_list = [int(input()) for _ in range(N)]
money_list.reverse()
cnt = 0
for each in money_list:
    while True:
        if K - each < 0:
            break
        else:
            K -= each
            cnt += 1

print(cnt)
