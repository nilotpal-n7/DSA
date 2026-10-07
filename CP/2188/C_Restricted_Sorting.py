import sys
from collections import defaultdict, deque
sys.setrecursionlimit(2000)

def solve():
    data = sys.stdin.read().split()
    if not data:
        return
    it = iter(data)
    try:
        t = int(next(it))
    except StopIteration:
        return
    out = []

    for _ in range(t):
        try:
            n = int(next(it))
            a = [int(next(it)) for _ in range(n)]
        except StopIteration:
            break

        b = sorted(a)
        if a == b:
            out.append("-1")
            continue
        min_g = b[0]
        max_g = b[-1]
        pos = defaultdict(deque)
        for i, v in enumerate(b):
            pos[v].append(i)

        p = [pos[v].popleft() for v in a]
        ans = float("inf")
        start = 0
        mx = -1

        for i in range(n):
            if p[i] > mx:
                mx = p[i]

            if mx == i:
                bad = False
                for k in range(start, i + 1):
                    if a[k] != b[k]:
                        bad = True
                        break

                if bad:
                    seg = b[start:i + 1]
                    prev = seg[0]

                    for j in range(1, len(seg)):
                        cur = seg[j]
                        if cur == prev:
                            continue

                        opt1 = cur - prev
                        opt2 = prev - min_g
                        opt3 = max_g - cur
                        opt4 = min(max_g - prev, cur - min_g)
                        ans = min(ans, max(opt1, opt2, opt3, opt4))
                        prev = cur

                start = i + 1
        out.append("-1" if ans == float("inf") else str(ans))
    sys.stdout.write("\n".join(out))

if __name__ == "__main__":
    solve()
