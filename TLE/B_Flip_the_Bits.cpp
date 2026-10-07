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
    string s1, s2;
    cin>>s1>>s2;

    int z1{}, o1{}, z2{}, o2{};
    rpt(i, n) {
        if(s1[i]=='1') o1++;
        else z1++;
        if(s2[i]=='1') o2++;
        else z2++;
    }

    if(z1!=z2 || o1!=o2) {
        cout<<"NO"<<"\n"; return;
    }
    bool poss{1}, inv{};

    rrpt(i, n) {
        if(inv) {
            if(s1[i]!=s2[i]) {
                if(s1[i]=='0') o1--;
                else z1--;
                continue;
            }
        }
        else {
            if(s1[i]==s2[i]) {
                if(s1[i]=='1') o1--;
                else z1--;
                continue;
            }
        }

        if(o1 != z1) {
            poss = 0; break;
        }
        swap(z1, o1);
        inv = !inv;

        if(inv) {
            if(s1[i] == '0') o1--;
            else z1--;
        }
        else {
            if(s1[i] == '1') o1--;
            else z1--;
        }
    }

    cout<<(poss?"YES":"NO")<<"\n";
}

int main() {
    fastio();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}
