#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define eb emplace_back
#define ub upper_bound
#define lb lower_bound
#define mne *min_element
#define mxe *max_element
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

// void solve() {
//     int n; cin>>n;
//     vi x(n); read(x);
//     vi dp(n, 1);

//     rpt(i, n) rpt(j, i)
//         if(x[j]<x[i])
//             dp[i] = max(dp[i], 1+dp[j]);

//     cout<<mxe(all(dp))<<"\n";
// }

// void solve() {
//     int n; cin>>n;
//     vi a(n); read(a);
//     vector<int> dp(n, 1), parent(n, -1);

//     for(int i = 0; i < n; i++) {
//         for(int j = 0; j < i; j++) {
//             if(a[j] < a[i] && dp[j] + 1 > dp[i]) {
//                 dp[i] = dp[j] + 1;
//                 parent[i] = j;
//             }
//         }
//     }

//     // find LIS end
//     int idx = max_element(dp.begin(), dp.end()) - dp.begin();

//     // reconstruct
//     vector<int> lis;
//     while(idx != -1) {
//         lis.push_back(a[idx]);
//         idx = parent[idx];
//     }
//     reverse(lis.begin(), lis.end());
// }

void solve() {
    int n; cin >> n;
    vi x(n); read(x);
    vi tails;

    for(int v: x) {
        auto it = lb(all(tails), v);
        if(it == tails.end()) tails.pb(v);
        else *it = v;
    }

    cout<<sz(tails)<<"\n";
}

// void solve() {
//     int n; cin >> n;
//     vector<int> a(n);
//     for(int &x : a) cin >> x;

//     vector<int> tails;          // values
//     vector<int> pos;            // positions
//     vector<int> parent(n, -1);  // reconstruction

//     for(int i = 0; i < n; i++) {
//         int x = a[i];

//         auto it = lower_bound(tails.begin(), tails.end(), x);
//         int idx = it - tails.begin();

//         if(it == tails.end()) {
//             tails.push_back(x);
//             pos.push_back(i);
//         } else {
//             *it = x;
//             pos[idx] = i;
//         }

//         // set parent
//         if(idx > 0) parent[i] = pos[idx - 1];
//     }

//     // reconstruct LIS
//     vector<int> lis;
//     int cur = pos.back(); // last index of LIS

//     while(cur != -1) {
//         lis.push_back(a[cur]);
//         cur = parent[cur];
//     }

//     reverse(lis.begin(), lis.end());

//     // output
//     cout << lis.size() << "\n";
//     for(int v : lis) cout << v << " ";
// }

int main() {
    fastio();
    int t{1}; // cin >> t;
    while(t--) solve();
    return 0;
}
