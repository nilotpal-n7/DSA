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
    int n; cin>>n;
    v<int> a(n);
    rpt(i, n) cin>>a[i];
    v<v<int>> g(n);
    rpt(i, n) rpt(j, n-i-1) {
        int k = j+i+1;
        if(a[i]==a[k]) continue;
        g[i].pb(k);
        g[k].pb(i);
    }

    bool all_same = true;
    rpt(i, n-1) {
        int k = i+1;
        if (a[k] != a[0]) {
            all_same = false;
            break;
        }
    }

    if(all_same) {
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
    int root{};
    int diff{-1};

    rpt(i, n-1) {
        int k = i+1;
        if(a[k] != a[root]) {
            diff = k;
            cout<<root+1<<" "<<k+1<<"\n";
            break;
        }
    }

    rpt(i, n-1) {
        int k = i+1;
        if(k == diff) continue;

        if(a[k] != a[root])
            cout<<root+1<<" "<<k+1<<"\n";
        else cout<<diff+1<<" "<<k+1<<"\n";
    }
}

int main() {
    fastio();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}
