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
    int energy; cin>>energy;
    string ladder_operators; cin>>ladder_operators;
    int momentum{}, position{};
    int dp_dx{}, quanta{};

    // Total energy should be equal to the number of characters in the string,
    // since each character represents one unit of energy.
    rpt(psi, energy) {
        if(ladder_operators[psi] == '(') momentum++; // ladder_operators operator on wavefunction in momentum space increases momentum by 1
        else if(ladder_operators[psi] == '[') position++; // ladder_operators operator on wavefunction in position space increases position by 1
        else if(ladder_operators[psi] == ']') { 
            if(position > 0) position--; // ladder_operators operator on wavefunction in position space decreases position by 1
            else if (dp_dx > 0) dp_dx--; // if we can't decrease position, we can use dp_dx to fix it
            else {dp_dx++; quanta++;} // if we can't fix it with dp_dx, we need to use a quanta of energy to fix it
        }
        else {
            if(momentum > 0) momentum--; // ladder_operators operator on wavefunction in momentum space decreases momentum by 1
            else if (dp_dx > 0) dp_dx--; // if we can't decrease momentum, we can use dp_dx to fix it
            else {dp_dx++; quanta++;} // if we can't fix it with dp_dx, we need to use a quanta of energy to fix it
        }
    }

    // Heisenburg unsertanity principle: we can only know the total energy,
    // not how it's distributed between momentum and position.
    // So we take the worst case scenario where all the energy is in one of them,
    // and we need to use dp_dx to fix the other one.
    // The remaining energy can be used to fix the remaining momentum and position pairs.
    cout<<(quanta + (momentum+position - dp_dx)/2)<<"\n";
}

int main() {
    fastio();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}
