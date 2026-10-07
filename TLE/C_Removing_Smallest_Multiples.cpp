#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ub upper_bound
#define lb lower_bound
#define all(v) v.begin(), v.end()
#define rpt(i, t) for(int i{}; i<t; i++)
#define ppc __builtin_popcount
#define v vector
#define p pair
#define um unordered_map
#define us unordered_set
const int MOD=1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;

    while(t--) {
        int n; cin>>n;
        string s{}; cin>>s;
        v<bool> removed(n, 0);
        ll ans = 0;

        rpt(i, n) {
            int k = i+1;

            for(int j{i}; j<n; j+=k) {
                if(s[j]=='1') break;

                if (!removed[j]) {
                    removed[j] = 1;
                    ans += k;
                }
            }
        }

        cout<<ans<<"\n";
    }    
    return 0;
}
