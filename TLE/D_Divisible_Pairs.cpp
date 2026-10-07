#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define ub upper_bound
#define lb lower_bound
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define rpt(i, t) for(int i{}; i<t; i++)
#define rrpt(i, t) for(int i{t-1}; i>=0; i--)
#define ppc __builtin_popcount
#define v vector
#define p pair
#define pi p<int, int>
#define pll p<ll, ll>
#define um unordered_map
#define us unordered_set
#define ff first
#define ss second
#define sz(x) (int)(x).size()
#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr)

const int MOD = 1e9 + 7;
const ll INFLL = (ll)4e18;
const int INF = (int)2e9;

ll modexp(ll a, ll b, ll m = MOD) {
    ll res{1};
    while(b) {
        if(b & 1) res = (res*a) % m;
        a = (a*a) % m;
        b >>= 1;
    }
    return res;
}

ll modinv(ll a, ll m = MOD) {
    return modexp(a, m-2, m);
}

template<typename T>
void read(v<T> &a) {
    for(auto &x: a) cin>>x;
}

template<typename T>
void print(const v<T> &a) {
    for(const auto &x: a) cout<<x<<' ';
    cout<<'\n';
}

void solve() {
    int n, x, y;
    cin>>n>>x>>y;
    map<int, map<int, int>> mp;
    rpt(i, n) {
        int a; cin>>a;
        mp[a%y][a%x]++;
    }

    ll ans{};
    for(auto &[g, f]: mp) {
        for(auto &[r, c]: f) {
            int need = (x-r)%x;
            if(!f.count(need)) continue;
            if(r==need) ans += 1LL*c*(c-1)/2;
            else if(r<need) ans += 1LL*c*f[need];
        }
    }

    cout<<ans<<"\n";
}

int main() {
    fastio();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}
