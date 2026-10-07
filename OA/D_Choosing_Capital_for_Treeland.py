import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

n = int(input())
g = [[] for _ in range(n+1)]
cost = [0]*(n+1)

for _ in range(n-1):
    u, v = map(int, input().split())
    g[u].append((v, 0))
    g[v].append((u, 1))

def dfs_all(u, p):
    for v, c in g[u]:
        if v == p:
            continue
        cost[1] += c
        dfs_all(v, u)

def dfs_specific(u, p):
    for v, c in g[u]:
        if v == p:
            continue
        if c == 0:
            cost[v] = cost[u] + 1
        else:
            cost[v] = cost[u] - 1
        dfs_specific(v, u)

dfs_all(1, -1)
dfs_specific(1, -1)
best = min(cost[1:])
print(best)
print(*[i for i in range(1, n+1) if cost[i] == best])
