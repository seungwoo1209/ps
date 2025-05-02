import sys


def calc(startrow, endrow, startcol, endcol):
    global white, blue
    total = 0
    for i in range(startrow, endrow + 1):
        for j in range(startcol, endcol + 1):
            total += arr[i][j]
    if total == 0:
        white += 1
        return
    elif total == (endrow - startrow + 1) * (endcol - startcol + 1):
        blue += 1
        return
    else:
        # 정수 중간값 계산 (//)
        midrow = (startrow + endrow) // 2
        midcol = (startcol + endcol) // 2

        # 4등분 재귀 호출 (모두 정수 인덱스)
        calc(startrow, midrow, startcol, midcol)
        calc(startrow, midrow, midcol + 1, endcol)
        calc(midrow + 1, endrow, startcol, midcol)
        calc(midrow + 1, endrow, midcol + 1, endcol)


def main():
    n = int(sys.stdin.readline())
    for _ in range(n):
        row = list(map(int, sys.stdin.readline().split()))
        arr.append(row)
    calc(0, n-1, 0, n - 1)


if __name__ == '__main__':
    blue = 0
    white = 0
    arr = []
    main()
    print(white)
    print(blue)
