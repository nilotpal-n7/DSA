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
        int res{};
        map<int, int> cnt;
        rpt(i, n) cnt[a[i]]++;

        while(!cnt.empty()) {
            auto it = cnt.begin();

            while(it != cnt.end()) {
                int curr = it->first;
                it->second--;
                auto nxt = it;
                nxt++;

                if(it->second == 0) cnt.erase(it);
                if(nxt->first != curr + 1) break;
                it = nxt;
            }

            res++;
        }
        cout<<res<<"\n";
    }
    return 0;
}
