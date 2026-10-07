#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> b(n);
    map<int, vector<int>> groups;

    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        groups[b[i]].push_back(i);
    }

    bool possible = true;
    for (auto const& [value, indices] : groups) {
        if (indices.size() % value != 0) {
            possible = false;
            break;
        }
    }

    if (!possible) {
        cout << -1 << endl;
        return;
    }

    vector<int> a(n);
    int new_val = 1;

    for (auto const& [b_value, indices] : groups) {
        for (size_t i = 0; i < indices.size(); ++i) {
            a[indices[i]] = new_val;
            if ((i + 1) % b_value == 0) new_val++;
        }
    }

    for (int i = 0; i < n; ++i) cout << a[i] << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
