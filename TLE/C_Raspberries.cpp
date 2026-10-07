#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int &x : a) cin >> x;

        if (k == 2) {
            bool ok = false;
            for (int x : a) if (x % 2 == 0) ok = true;
            cout << (ok ? 0 : 1) << '\n';
        }

        else if (k == 3) {
            bool ok = false;
            bool has2 = false;
            for (int x : a) {
                if (x % 3 == 0) ok = true;
                if (x % 3 == 2) has2 = true;
            }
            if (ok) cout << 0 << '\n';
            else if (has2) cout << 1 << '\n';
            else cout << 2 << '\n';
        }

        else if (k == 5) {
            int ans = 5;
            for (int x : a)
                ans = min(ans, (5 - x % 5) % 5);
            cout << ans << '\n';
        }

        else if (k == 4) {
            int cnt2 = 0, cnt4 = 0;
            for (int x : a) {
                if (x % 4 == 0) cnt4++;
                else if (x % 2 == 0) cnt2++;
            }

            int ans;
            if (cnt4 >= 1 || cnt2 >= 2) ans = 0;
            else if (cnt2 == 1) ans = 1;
            else ans = 2;

            for (int x : a) {
                int need = (4 - x % 4) % 4;
                ans = min(ans, need);
            }

            cout << ans << '\n';
        }
    }
    return 0;
}
