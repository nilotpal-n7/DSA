import sys
input = sys.stdin.readline
t = int(input())

# hehe python baba ki jai

for _ in range(t):
    n, x = map(int, input().split())
    a = list(map(int, input().split()))
    total = sum(a)
    l, r = -1, -1

    if total % x != 0:
        print(n)
        continue

    for i in range(n):
        if a[i] % x != 0:
            l = i
            break

    for i in range(n - 1, -1, -1):
        if a[i] % x != 0:
            r = i
            break

    if l == -1:
        print(-1)
        continue

    ans = max(n-l-1, r)
    print(ans)
