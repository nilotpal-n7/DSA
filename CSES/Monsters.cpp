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

void solve() {
    int n, m; cin>>n>>m;
    v<string> g(n); read(g);
    vi dd = {1, -1, 0, 0};
    string dir = "DULR";

    queue<pi> qm; pi start;
    v<vi> distM(n, vi(m, INF));
    rpt(i, n) rpt(j, m) { // push all monsters
        if(g[i][j] == 'M') {
            qm.push({i, j});
            distM[i][j] = 0;
        }
        if(g[i][j] == 'A') start = {i, j};
    }

    while(!qm.empty()) { // BFS for monsters
        auto [x, y] = qm.front(); qm.pop();

        rpt(d, 4) {
            int nx = x + dd[d], ny = y + dd[3-d];

            if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
            if(g[nx][ny] == '#') continue;
            if(distM[nx][ny] != INF) continue;

            distM[nx][ny] = distM[x][y] + 1;
            qm.push({nx, ny});
        }
    }

    queue<pi> qa;
    qa.push(start);
    v<vi> distA(n, vi(m, -1));
    v<v<pi>> par(n, v<pi>(m, {-1, -1}));
    distA[start.ff][start.ss] = 0;
    bool poss{}; pi end;

    while(!qa.empty()) { // BFS for A
        auto [x, y] = qa.front(); qa.pop();
        if(x == 0 || y == 0 || x == n-1 || y == m-1) {
            end = {x, y}; poss = 1; break; // escape condition (boundary)
        }

        rpt(d, 4) {
            int nx = x + dd[d], ny = y + dd[3-d];

            if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
            if(g[nx][ny] == '#') continue;
            if(distA[nx][ny] != -1) continue;
            if(distA[x][y] + 1 >= distM[nx][ny]) continue; // safety check

            distA[nx][ny] = distA[x][y] + 1;
            par[nx][ny] = {x, y};
            qa.push({nx, ny});
        }
    }

    if(!poss) { cout<<"NO\n"; return; }

    string path; // reconstruct path
    while(end != start) {
        int x = end.ff, y = end.ss;
        auto [px, py] = par[x][y];

        if(px == x-1) path += 'D';
        else if(px == x+1) path += 'U';
        else if(py == y-1) path += 'R';
        else if(py == y+1) path += 'L';

        end = par[x][y];
    }
    
    reverse(all(path));
    cout<<"YES\n";
    cout<<path.size()<<"\n";
    cout<<path<<"\n";
}

int main() {
    fastio();
    int t{1}; // cin >> t;
    while(t--) solve();
    return 0;
}
