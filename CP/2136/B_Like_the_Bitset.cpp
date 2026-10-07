#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    // Impossible if k consecutive '1's
    int consec = 0;
    for (char c : s) {
        if (c == '1') consec++;
        else consec = 0;
        if (consec >= k) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
    vector<int> p(n);
    int left = 1, right = n;

    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') p[i] = right--;
        else p[i] = left++;
    }

    for (int i = 0; i < n; ++i) {
        cout << p[i] << (i == n - 1 ? "\n" : " ");
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
