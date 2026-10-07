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
#define vi v<int>
#define vll v<ll>
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

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM =
            chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

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
    string s; cin>>s;
    if(is_sorted(all(s))) {
        cout<<"Bob\n"; return;
    }

    cout<<"Alice\n";
    int zc{}; vi st;
    rpt(i, n) if(s[i]=='0') zc++;
    rpt(i, zc) if(s[i]=='1') st.pb(i+1);
    rpt(i, n-zc) if(s[i+zc]=='0') st.pb(i+zc+1);

    cout<<st.size()<<" "<<"\n";
    rpt(i, st.size()) cout<<st[i]<<" ";
    cout<<"\n";
}

int main() {
    fastio();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}
