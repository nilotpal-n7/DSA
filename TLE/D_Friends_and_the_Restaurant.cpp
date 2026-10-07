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
        v<int> x(n), y(n), z(n);
        rpt(i, n) cin>>x[i];
        rpt(i, n) cin>>y[i];
        rpt(i, n) z[i] = y[i]-x[i];
        sort(all(z)); int ans{};

        int l{}, r{n-1};
        int currSum = z[l]+z[r];

        while(l < r) {
            if(currSum>=0) {
                ans++;
                currSum -= z[r--];
                currSum += z[r];
            }
            
            currSum -= z[l++];
            currSum += z[l];
        }

        cout<<ans<<"\n";
    }
    return 0;
}
