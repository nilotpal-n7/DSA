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

struct Edge {
    int u, v;
    ll w;
};

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    v<ll> a(n);
    read(a);

    // DSU
    vi parent(n), szz(n, 1);
    iota(all(parent), 0);

    function<int(int)> find = [&](int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    };

    auto unite = [&](int a, int b) {
        a = find(a); b = find(b);
        if(a == b) return;
        if(szz[a] < szz[b]) swap(a, b);
        parent[b] = a;
        szz[a] += szz[b];
    };

    // existing roads
    rpt(i, m) {
        int u, v; cin >> u >> v;
        u--; v--;
        unite(u, v);
    }

    // find minimum node in each component
    um<int, int> comp_min; // root -> node index
    rpt(i, n) {
        int r = find(i);
        if(!comp_min.count(r) || a[i] < a[comp_min[r]])
            comp_min[r] = i;
    }

    // get all component representatives
    vi reps;
    for(auto &[r, node]: comp_min)
        reps.pb(node);

    // find global minimum
    int global_min = reps[0];
    for(int x: reps)
        if(a[x] < a[global_min])
            global_min = x;

    v<Edge> edges;

    // connect components via global minimum
    for(int x: reps) {
        if(x == global_min) continue;
        edges.pb({global_min, x, a[global_min] + a[x]});
    }

    // special edges
    rpt(i, k) {
        int u, v; ll w;
        cin >> u >> v >> w;
        u--; v--;
        edges.pb({u, v, w});
    }

    // Kruskal
    sort(all(edges), [](auto &a, auto &b) {
        return a.w < b.w;
    });

    ll ans = 0;
    for(auto &e: edges) {
        if(find(e.u) != find(e.v)) {
            unite(e.u, e.v);
            ans += e.w;
        }
    }

    cout << ans << "\n";
}

int main() {
    fastio();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}
