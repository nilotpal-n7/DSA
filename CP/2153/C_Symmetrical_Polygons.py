import sys
from collections import Counter

def solve():
    n = int(sys.stdin.readline())
    a = list(map(int, sys.stdin.readline().split()))

    counts = Counter(a)
    total_perimeter = sum(a)
    num_sticks = n

    while True:
        if num_sticks < 3 or not counts:
            print(0)
            return

        l_max = max(counts.keys())
        
        if total_perimeter <= 2 * l_max:
            to_remove = l_max
        else:
            odd_lengths = [length for length, count in counts.items() if count % 2 != 0]

            if len(odd_lengths) <= 2:
                print(total_perimeter)
                return
            else:
                to_remove = min(odd_lengths)

        total_perimeter -= to_remove
        counts[to_remove] -= 1
        num_sticks -= 1
        if counts[to_remove] == 0:
            del counts[to_remove]


def main():
    try:
        num_test_cases = int(sys.stdin.readline())
        for _ in range(num_test_cases):
            solve()
    except (IOError, ValueError):
        pass

if __name__ == "__main__":
    main()
