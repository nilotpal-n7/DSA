#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t{};
    cin>>t;

    while(t--) {
        ll n{}, m{}, l{INT_MAX};
        cin>>n;
        vector<ll> b(n, 0);

        for(int i{}; i<n; i++) {
            cin>>m;
            vector<ll> a(m, 0);
            for(int j{}; j<m; j++) cin>>a[j];

            sort(a.begin(), a.end());
            b[i] = a[1];
            l = min(l, a[0]);
        }

        sort(b.begin(), b.end());
        ll ans = accumulate(b.begin(), b.end(), 0);
        cout<<(ans - b[0] + l)<<endl;
    }

    return 0;
}
