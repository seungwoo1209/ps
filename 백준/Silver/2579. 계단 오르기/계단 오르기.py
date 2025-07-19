how_many_stairs = int(input())

stairs = [int(input()) for _ in range(how_many_stairs)]

if how_many_stairs == 1:
    print(stairs[0])
    exit()

dp = [[0 for _ in range(how_many_stairs)] for _ in range(2)]

dp[0][0] = stairs[0]
dp[1][0] = stairs[0]

dp[0][1] = dp[1][0] + stairs[1]
# dp[1][1] = max(dp[0][-1], dp[1][-1]) + stairs[1]
dp[1][1] = stairs[1]


for i in range(2, how_many_stairs):
    dp[0][i] = dp[1][i-1] + stairs[i]
    dp[1][i] = max(dp[0][i-2], dp[1][i-2] ) + stairs[i]

print(max(dp[0][how_many_stairs-1], dp[1][how_many_stairs-1]))