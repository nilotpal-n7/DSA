#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ub upper_bound
#define lb lower_bound
#define all(v) v.begin(), v.end()
#define rpt(i, t) for(int i{}; i<t; i++)
#define ppc __builtin_popcount
#define v vector
#define p pair
#define um unordered_map
#define us unordered_set
const int MOD=1e9+7;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin>>t;

    while(t--) {
        int n, q; cin>>n>>q;
        v<int> a(n);
        rpt(i, n) cin>>a[i];
        v<p<int, ll>> h(n);
        h[0] = {a[0], 1LL*a[0]};
        rpt(i, n-1) h[i+1] =
            {max(h[i].first, a[i+1]),
            h[i].second + 1LL*a[i+1]};

        
        while(q--) {
            int k; cin>>k;
            int idx = ub(all(h), p<int, ll>{k, LLONG_MAX}) - h.begin() - 1;
            (idx<0) ? cout<<0<<" " :
            cout<<h[idx].second<<" ";
        }

        cout<<"\n";
    }
    return 0;
}
