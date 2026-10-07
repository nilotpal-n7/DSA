import sys
input = sys.stdin.readline

INF = 10**18

def cost3(x, y, z):
    return max(x, y, z) - min(x, y, z)

def solve_linear(arr):
    m = len(arr)
    if m == 0:
        return 0
    if m < 2:
        return INF

    dp = [INF] * (m + 1)
    dp[0] = 0

    for i in range(1, m + 1):
        if i >= 2 and dp[i - 2] != INF:
            cost = abs(arr[i - 2] - arr[i - 1])
            dp[i] = min(dp[i], dp[i - 2] + cost)

        if i >= 3 and dp[i - 3] != INF:
            cost = cost3(arr[i - 3], arr[i - 2], arr[i - 1])
            dp[i] = min(dp[i], dp[i - 3] + cost)

    return dp[m]

def solve_case(n, a):
    op = solve_linear(a)

    if n >= 2:
        sub = a[1:-1]
        rc = solve_linear(sub)
        if rc != INF:
            wc = abs(a[-1] - a[0])
            op = min(op, wc + rc)

    if n >= 3:
        sub = a[1:-2]
        rc = solve_linear(sub)
        if rc != INF:
            wc = cost3(a[-2], a[-1], a[0])
            op = min(op, wc + rc)

    if n >= 3:
        sub = a[2:-1]
        rc = solve_linear(sub)
        if rc != INF:
            wc = cost3(a[-1], a[0], a[1])
            op = min(op, wc + rc)

    return op

def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        a = list(map(int, input().split()))
        print(solve_case(n, a))

if __name__ == "__main__":
    main()
