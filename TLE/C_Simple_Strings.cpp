#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define eb emplace_back
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

struct c_hash {
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

vi primes;
void compPrimes(int n) {
    v<bool> isPrime(n+1, true);
    isPrime[0] = isPrime[1] = false;

    for(int p{2}; p*p<=n; p++)
        if(isPrime[p])
            for(int i=p*p; i<=n; i+=p)
                isPrime[i] = false;

    for(int p{2}; p<=n; p++)
        if(isPrime[p])
            primes.push_back(p);
}

vll fact(1, 1);
void compFact(ll m, int n) {
    rpt(k, n-1) {
        int i = k+1;
        fact.pb((fact.back()*i) % m);
    }
}

void solve() {
    string s; cin>>s;
    int l = sz(s);
    
    rpt(i, l-2) {
        int k = i+1;
        if(s[k]==s[i]) {
            if(s[k] != 'a') {
                if(s[k+1] != 'a') s[k]='a';
                else if(s[k] != 'b') s[k]='b';
                else s[k] = 'c';
            }
            else {
                if(s[k+1] != 'b') s[k]='b';
                else s[k] = 'c';
            }
        }
    }

    if(s[l-1]==s[l-2]) {
        if(s[l-1]=='a') s[l-1]='b';
        else s[l-1] = 'a';
    }
    cout<<s<<"\n";
}

int main() {
    fastio();
    // int t; cin >> t;
    // while(t--) solve();
    solve();
    return 0;
}
