import sys
import bisect

# Increase recursion depth to handle deep recursion if necessary
sys.setrecursionlimit(300000)

def solve():
    # Use fast I/O
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    iterator = iter(input_data)
    
    try:
        num_test_cases = int(next(iterator))
    except StopIteration:
        return

    out_lines = []

    for _ in range(num_test_cases):
        try:
            n = int(next(iterator))
            m = int(next(iterator))
        except StopIteration:
            break
            
        extras = []
        extras_by_u = [[] for _ in range(n + 1)]
        
        for _ in range(m):
            u = int(next(iterator))
            v = int(next(iterator))
            extras.append({'u': u, 'v': v})
            extras_by_u[u].append(v)
            
        # 1. Compute Max Reach (M[u]) for every vertex
        max_reach = [i + 1 for i in range(n + 1)]
        max_reach[n] = n
        for e in extras:
            if e['v'] > max_reach[e['u']]:
                max_reach[e['u']] = e['v']
        
        # 2. Identify all vertices that are starts of extra edges
        # This helps in optimizing the patching process for Part B and Part A
        bridge_starts = sorted([u for u in range(1, n) if extras_by_u[u]])

        # func_store[y] stores the intervals (start, end, val) for f(x, y) where x > y
        # Implicitly, x not in these intervals (and x > y) has f(x, y) = 0 (Loss for Tom)
        func_store = {}
        total_ans = 0
        
        # Helper function to query the value of f(q, y) from sorted intervals
        def get_val(intervals, q):
            l, r = 0, len(intervals) - 1
            while l <= r:
                mid = (l + r) // 2
                s, e, v = intervals[mid]
                if s <= q <= e:
                    return (True, v)
                elif q < s:
                    r = mid - 1
                else:
                    l = mid + 1
            return (False, 0)

        # Iterate y from n-1 down to 1
        for y in range(n - 1, 0, -1):
            K = max_reach[y]
            K_intervals = func_store.get(K, [])
            
            # --- Part B: Calculate f(x, y) for x > y ---
            cand = []
            
            # 1. Base Interval: [y+1, K-1]
            # For x in this range, x+1 <= K, so Tom wins with cost 1 (Wait at K)
            if y + 1 <= K - 1:
                cand.append((y + 1, K - 1, 1))
            
            # 2. Shifted Intervals from K
            # If f(x', K) = v, then f(x, y) = 1 + v where x = x' - 1
            # We filter for x > y
            for s, e, v in K_intervals:
                ns, ne = max(y + 1, s - 1), e - 1
                
                if ns <= ne:
                    # Merge optimization
                    if cand and cand[-1][2] == v + 1 and cand[-1][1] == ns - 1:
                        cand[-1] = (cand[-1][0], ne, v + 1)
                    else:
                        cand.append((ns, ne, v + 1))
            
            # 3. Patch intervals for u that have extra edges
            # We strictly patch u in [min_cand, max_cand] intersecting with bridge_starts
            final_intervals = []
            
            # Find relevant u's efficiently
            if not cand:
                relevant_us = []
            else:
                low = cand[0][0]
                high = cand[-1][1]
                idx_start = bisect.bisect_left(bridge_starts, low)
                idx_end = bisect.bisect_right(bridge_starts, high)
                relevant_us = bridge_starts[idx_start:idx_end]
            
            u_ptr = 0
            
            for s, e, v in cand:
                curr_s = s
                
                # Split interval [s, e] by relevant_us
                while u_ptr < len(relevant_us) and relevant_us[u_ptr] <= e:
                    u = relevant_us[u_ptr]
                    
                    if u < curr_s:
                        u_ptr += 1
                        continue
                        
                    # Add valid range before u
                    if u > curr_s:
                        final_intervals.append((curr_s, u - 1, v))
                    
                    # Compute exact cost for u
                    # Option 1: Walk to u+1 (Cost v)
                    # Option 2: Jump u -> v_jump
                    # Jerry will choose the option that makes Tom Lose (cost 0) if possible.
                    # Otherwise, Jerry maximizes the cost.
                    
                    can_escape = False
                    max_cost = v
                    
                    for v_jump in extras_by_u[u]:
                        wins_here = False
                        cost_here = 0
                        
                        if v_jump <= K:
                            wins_here = True
                            cost_here = 1
                        else:
                            is_w, c = get_val(K_intervals, v_jump)
                            if is_w:
                                wins_here = True
                                cost_here = 1 + c
                        
                        if not wins_here:
                            can_escape = True # Jerry escapes
                            # Optimization: if escape found, we can break if we treat it as 0
                            # But we need to ensure we don't count it.
                            break
                        else:
                            if cost_here > max_cost:
                                max_cost = cost_here
                    
                    if not can_escape:
                        final_intervals.append((u, u, max_cost))
                    
                    curr_s = u + 1
                    u_ptr += 1
                
                # Add remainder of the interval
                if curr_s <= e:
                    final_intervals.append((curr_s, e, v))
            
            func_store[y] = final_intervals
            # Add to total answer
            for s, e, v in final_intervals:
                total_ans += v * (e - s + 1)
                
            # --- Part A: Calculate f(x, y) for x < y ---
            # Propagate values backwards from y-1
            
            # Identify relevant bridges u < y
            idx_lim = bisect.bisect_left(bridge_starts, y)
            relevant_bridges = bridge_starts[:idx_lim]
            
            # Initial state: arriving at y is a Win for Tom (Cost 0 relative to arrival)
            # Effectively, f(y, y) = 0.
            current_val = 0 
            prev_x = y 
            
            if relevant_bridges:
                for u in reversed(relevant_bridges):
                    # Range (u, prev_x - 1] propagates current_val
                    count = (prev_x - 1) - u
                    if count > 0 and current_val > 0:
                        total_ans += count * current_val
                    
                    # Calculate value at bridge start u
                    # Option 1: Walk to u+1 (Cost current_val)
                    # Option 2: Jump u -> v_jump
                    
                    can_escape = False
                    max_cost = current_val
                    
                    for v_jump in extras_by_u[u]:
                        if v_jump > y: # Only jumps crossing y matter
                            wins_here = False
                            cost_here = 0
                            
                            if v_jump <= K:
                                wins_here = True
                                cost_here = 1
                            else:
                                is_w, c = get_val(K_intervals, v_jump)
                                if is_w:
                                    wins_here = True
                                    cost_here = 1 + c
                            
                            if not wins_here:
                                can_escape = True
                                break
                            else:
                                if cost_here > max_cost:
                                    max_cost = cost_here
                    
                    if can_escape:
                        current_val = 0
                    else:
                        current_val = max_cost
                    
                    if current_val > 0:
                        total_ans += current_val
                    prev_x = u
            
            # Remaining range [1, prev_x - 1]
            count = prev_x - 1
            if count > 0 and current_val > 0:
                total_ans += count * current_val

        out_lines.append(str(total_ans))

    print('\n'.join(out_lines))

if __name__ == '__main__':
    solve()
