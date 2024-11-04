import sys

line = sys.stdin.readline().strip()

N = len(line)
m = (-N)%8

line = line + '0'*m

for i in range((N+7)//8):
    print(line[8*i:8*(i+1)])
