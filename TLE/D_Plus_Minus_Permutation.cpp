#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;

    while(t--) {
        ll n, x, y;
        cin>>n>>x>>y;

        ll c = n/lcm(x, y);
        ll xc = n/x - c;
        ll yc = n/y - c;

        ll pos = xc*n - xc*(xc-1)/2;
        ll neg = yc*(yc+1)/2;
        cout<<pos-neg<<"\n";
    }

    return 0;
}
