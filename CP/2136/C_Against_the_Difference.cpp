#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    map<int, vector<int>> pos;
    for (int i = 0; i < n; ++i) pos[a[i]].push_back(i);
    vector<int> dp(n, 0);

    for (int i = 0; i < n; ++i) {
        int current_val = a[i];
        if (i > 0) dp[i] = dp[i-1];
        int len_of_block = current_val;

        if (len_of_block <= pos[current_val].size()) {
            int current_count_idx = lower_bound(pos[current_val].begin(), pos[current_val].end(), i) - pos[current_val].begin();
            
            if (current_count_idx >= len_of_block - 1) {
                int prev_block_end_idx = pos[current_val][current_count_idx - (len_of_block - 1)];
                int prev_len = 0;
                if (prev_block_end_idx > 0) prev_len = dp[prev_block_end_idx - 1];
                dp[i] = max(dp[i], prev_len + len_of_block);
            }
        }
    }

    cout << (n > 0 ? dp[n - 1] : 0) << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
