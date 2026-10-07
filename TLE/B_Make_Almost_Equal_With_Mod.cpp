#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;

    while(t--) {
        int n; cin>>n;
        vector<ll> a(n);
        for(int i{}; i<n; i++) cin>>a[i];

        for(int i{1}; i<60; i++) {
            ll mod = 1LL << i;
            unordered_set<ll> remainders;
            for(int j{}; j<n; j++)
                remainders.insert(a[j] % mod);

            if(remainders.size() == 2) {
                cout<<mod<<'\n';
                break;
            }
        }
    }
    
    return 0;
}
