import sys
import bisect


def main():
    N, K = map(int, sys.stdin.readline().split())
    if N > K:
        print(N - K)
        sys.exit(0)
    if N == K:
        print(0)
        sys.exit(0)
    location_arr = []
    location_arr.append(set([N]))
    location_arr.append(set())
    idx = 0
    answer_candidate = 100000
    while True:
        # print(idx)
        if K in location_arr[idx % 2]:
            if idx < answer_candidate:
                answer_candidate = idx
            break
        if idx > answer_candidate:
            break
        location_arr[(idx + 1) % 2] = set()
        for location in location_arr[idx % 2]:
            if location > K:
                if (idx + location - K) < answer_candidate:
                    answer_candidate = idx + location - K
                continue
            if location > (K / 2 + K / 4):
                if (idx + K - location) < answer_candidate:
                    answer_candidate = idx + K - location
                continue
            if location + 1 <= 100_000 and location + 1 not in location_arr[idx % 2]:
                location_arr[(idx + 1) % 2].add(location + 1)
            if location - 1 >= 0 and location - 1 not in location_arr[idx % 2]:
                location_arr[(idx + 1) % 2].add(location - 1)
            if location * 2 <= 100_000 and location * 2 not in location_arr[idx % 2]:
                location_arr[(idx + 1) % 2].add(location * 2)
        idx += 1
    print(answer_candidate)


if __name__ == '__main__':
    main()
