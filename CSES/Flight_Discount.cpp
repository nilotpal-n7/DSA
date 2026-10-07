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

// k = k discount
void solve() {
    int n, m; cin>>n>>m;
    v<v<pi>> g(n); rpt(i, m) {
        int x, y, z; cin>>x>>y>>z;
        x--; y--;
        g[x].pb({y, z});
    }

    priority_queue<tuple<ll, int, bool>, v<tuple<ll, int, bool>>, greater<>> pq;
    v<vll> dist(n, vll(2, INFLL)); pq.push({0, 0, 0}); dist[0][0] = 0;

    while(!pq.empty()) {
        auto [d, u, used] = pq.top(); pq.pop();
        if(d > dist[u][used]) continue;

        for(auto &[v, w]: g[u]) {
            // normal move
            if(dist[v][used] > d + w) {
                dist[v][used] = d + w;
                pq.push({dist[v][used], v, used});
            }

            // use discount
            if(!used) {
                if(dist[v][1] > d + w/2) {
                    dist[v][1] = d + w/2;
                    pq.push({dist[v][1], v, 1});
                }
            }
        }
    }

    cout<<min(dist[n-1][0], dist[n-1][1])<<"\n";
}

// only for k=1 discount

// void solve() {
//     int n, m; cin>>n>>m;
//     v<v<pi>> g(n), rg(n);

//     v<tuple<int,int,ll>> edges;

//     rpt(i, m) {
//         int x, y; ll z;
//         cin>>x>>y>>z;
//         x--; y--;

//         g[x].pb({y, z});
//         rg[y].pb({x, z}); // reverse

//         edges.pb({x, y, z});
//     }

//     auto djk = [&](int src, v<v<pi>> &gr) {
//         vll dist(n, INFLL);
//         priority_queue<pll, v<pll>, greater<>> pq;

//         dist[src] = 0;
//         pq.push({0, src});

//         while(!pq.empty()) {
//             auto [d, u] = pq.top(); pq.pop();
//             if(d > dist[u]) continue;

//             for(auto &[v, w]: gr[u]) {
//                 if(dist[v] > d + w) {
//                     dist[v] = d + w;
//                     pq.push({dist[v], v});
//                 }
//             }
//         }

//         return dist;
//     };

//     vll dist1 = djk(0, g);
//     vll distN = djk(n-1, rg);

//     ll ans = INFLL;

//     for(auto &[u, v, w]: edges) {
//         if(dist1[u] == INFLL || distN[v] == INFLL) continue;
//         ans = min(ans, dist1[u] + w/2 + distN[v]);
//     }

//     cout<<ans<<"\n";
// }

int main() {
    fastio();
    int t{1}; // cin >> t;
    while(t--) solve();
    return 0;
}
