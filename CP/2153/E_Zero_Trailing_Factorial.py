import sys
input = sys.stdin.readline

M = 10**7
P = [1]*(M+1)
t = int(input())

for i in range(2, M+1):
    if P[i] == 1:
        for j in range(i, M+1, i):
            P[j] = i

def f(n, p):
    cnt = 0
    while n:
        n //= p
        cnt += n
    return cnt

for _ in range(t):
    n, m = map(int, input().split())
    p = set()

    for i in range(n, 0, -1):
        x = i
        while x > 1:
            p.add(P[x])
            x //= P[x]
        if P[i] == i: break

    ans = 0

    
