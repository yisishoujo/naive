import sys

a = []

N = int(sys.stdin.readline())

for n in range(N):
    l = int(sys.stdin.readline())
    if l not in a:
        a.append(l)

for num in sorted(a):
    print(num)
