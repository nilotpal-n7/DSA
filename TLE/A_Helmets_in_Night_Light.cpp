#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	ll t{};
	cin>>t;

	while (t--) {
		ll n{}, p{};
		cin>>n>>p;
		vector<pair<ll, ll>> v(n, {0, 0});
		vector<ll> a(n, 0), b(n, 0);
		for(int i{}; i<n; i++) cin>>a[i];
		for(int i{}; i<n; i++) cin>>b[i];
		for(int i{}; i<n; i++) v[i] = {b[i], a[i]};
		sort(v.begin(), v.end());
        ll min_cost{p}, alr_shrd{1};

        for(auto it: v) {
            ll can_shrd = it.second;
            ll shr_cost = it.first;
            if(shr_cost >= p) break;

            if(alr_shrd + can_shrd > n) {
                min_cost += (n - alr_shrd) * shr_cost;
                alr_shrd = n;
                break;
            }
            else {
                alr_shrd += can_shrd;
                min_cost += can_shrd * shr_cost;
            }
        }

        min_cost += (n - alr_shrd) * p;
        cout<<min_cost<<endl;
    }
    return 0;
}
