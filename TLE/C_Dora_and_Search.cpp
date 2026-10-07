#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(v) v.begin(), v.end()
#define rpt(i, t) for(int i{}; i<t; i++)
#define ppc __builtin_popcount
#define v(t) vector<t>
#define p(t) pair<t, t>
#define um(t1, t2) unordered_map<t1, t2>
#define us(t) unordered_set<t>
const int MOD=1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;

    while(t--) {
        int n; cin>>n;
        v(int) a(n);
        rpt(i, n) cin>>a[i];

        int l{1}, r{n};
        int i{}, j{n-1};
        while(i < j) {
            if(a[i] == l) {
                l++; i++;
                continue;
            }
            if(a[i] == r) {
                r--; i++;
                continue;
            }
            if(a[j] == l) {
                l++; j--;
                continue;
            }
            if(a[j] == r) {
                r--; j--;
                continue;
            }
            break;
        }

        (i>=j)? cout<<-1<<"\n":
        cout<<i+1<<" "<<j+1<<"\n";
    }
    return 0;
}
