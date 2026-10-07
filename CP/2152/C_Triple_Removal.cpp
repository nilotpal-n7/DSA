#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll get_base_cost(int start_idx, int cnt, const array<vector<ll>,3> &ps) {
    if (cnt < 3) return 0;

    int mod = start_idx % 3;
    int ps_start = start_idx / 3;
    int end = start_idx + cnt - 3;
    int ps_end = end / 3;

    if (ps_start > ps_end) return 0;
    return ps[mod][ps_end + 1] - ps[mod][ps_start];
}

void build_prefixes(const vector<int> &pos, array<vector<ll>,3> &ps) {
    int sz = (int)pos.size();
    if (sz < 3) {
        for (int r = 0; r < 3; ++r) ps[r].push_back(0);
        return;
    }

    int msize = sz - 2;
    vector<ll> m(msize);
    for (int i = 0; i < msize; ++i)
        m[i] = min((ll)pos[i+1] - pos[i], (ll)pos[i+2] - pos[i+1]);

    for (int r = 0; r < 3; ++r) {
        ps[r].push_back(0);
        for (int j = r; j < msize; j += 3)
            ps[r].push_back(ps[r].back() + m[j]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;

    while (t--) {
        int n, q; cin >> n >> q;
        vector<int> a(n+1);
        for (int i = 1; i <= n; ++i) cin >> a[i];
        vector<int> pos0, pos1, pref0(n+1,0), pref1(n+1,0);

        for (int i = 1; i <= n; ++i) {
            if (a[i]==0) pos0.push_back(i);
            else pos1.push_back(i);
            pref0[i] = pref0[i-1] + (a[i]==0);
            pref1[i] = pref1[i-1] + (a[i]==1);
        }

        array<vector<ll>,3> ps0, ps1;
        build_prefixes(pos0, ps0);
        build_prefixes(pos1, ps1);

        while (q--) {
            int l,r; cin >> l >> r;
            int cnt0 = pref0[r] - pref0[l-1];
            int cnt1 = pref1[r] - pref1[l-1];

            if (cnt0%3 != 0 || cnt1%3 != 0) {
                cout << -1 << '\n';
                continue;
            }

            int start0 = pref0[l-1];
            int start1 = pref1[l-1];

            ll base0 = get_base_cost(start0, cnt0, ps0);
            ll base1 = get_base_cost(start1, cnt1, ps1);
            ll ans = min(base0 + (ll)cnt1/3, base1 + (ll)cnt0/3);
            
            cout << ans << '\n';
        }
    }
    return 0;
}
