#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD{1000000007};
const ll MOD_1{MOD - 1};
ll modpow(ll, ll);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k{};
    cin>>k;

    ll nmp{1};
    int nm2{1};

    while(k--) {
        ll a;
        cin>>a;
        nmp = (nmp * (a % MOD_1)) % MOD_1;
        nm2 = (nm2 * (a % 2)) % 2;
    }

    ll exp = (nmp - 1 + MOD_1) % MOD_1;
    ll y = modpow(2, exp);

    ll sign = (nm2 == 0 ? 1 : MOD - 1);
    ll num = (y + sign) % MOD;
    ll x = num * 333333336 % MOD;

    cout<<x<<"/"<<y;
}

ll modpow(ll a, ll e) {
    ll r{1};
    while(e) {
        if (e & 1) r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}
