import sys
from collections import Counter


def main():
    line = sys.stdin.readline
    N, M = map(int, line().split())
    arr = list(map(int, line().split()))

    low = 0
    high = 1_000_000_000
    temp_sum_trees = 0
    while True:
        if high < low:
            break
        temp_sum_trees = 0
        mid = low + (high - low) // 2
        for i in range(len(arr)):
            if arr[i] > mid:
                temp_sum_trees += arr[i] - mid
        if temp_sum_trees >= M: # 충분하면
            low = mid + 1
        else: # 부족하면
            high = mid - 1
    print(high)



if __name__ == '__main__':
    main()