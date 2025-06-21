import sys

input = sys.stdin.readline
s = input()
chars = [c for c in s]

weight = 1
star_weight = None
sum = 0
for i in range(len(chars)-2):
    if chars[i] == '*':
        star_weight = weight
    else:
        sum += weight * int(chars[i])
    weight = (weight + 2) % 4

j=0
for j in range(0,10):
    if (sum + j * star_weight+ int(chars[len(chars)-2])) % 10 == 0:
        break

print(j)