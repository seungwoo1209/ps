import sys
import bisect

def main():
    N = int(sys.stdin.readline())
    arr = list(map(int, sys.stdin.readline().split()))
    valuelist = sorted(set(arr))
    result = []
    for i in range(N):
        index = bisect.bisect_left(valuelist,arr[i])
        result.append(str(index))
    print(' '.join(result))

if __name__ == '__main__':
    main()
