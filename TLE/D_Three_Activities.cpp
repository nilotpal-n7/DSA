#include <bits/stdc++.h>
using namespace std;

vector<int> findMax3(vector<int> &arr) {
	vector<pair<int, int>> tmp(arr.size());
	for (int i = 0; i < tmp.size(); i++) {
		tmp[i].first = arr[i];
		tmp[i].second = i;
	}

	sort(tmp.rbegin(), tmp.rend());
	vector<int> ans(3);
	for (int i = 0; i < 3; i++)
		ans[i] = tmp[i].second;

	return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;

    while(t--) {
        int n, ans{}; cin>>n;
        vector<int> a(n), b(n), c(n);
        for(int i=0; i<n; i++) cin>>a[i];
        for(int i=0; i<n; i++) cin>>b[i];
        for(int i=0; i<n; i++) cin>>c[i];

        vector<int> maxa = findMax3(a);
		vector<int> maxb = findMax3(b);
		vector<int> maxc = findMax3(c);

        for (int i{}; i<3; i++) {
			for (int j{}; j<3; j++) {
				for (int k{}; k<3; k++) {
					int x = maxa[i], y = maxb[j], z = maxc[k];
					if ((x==y) || (y==z) || (z==x))
						continue;
					ans = max(ans, a[x] + b[y] + c[z]);
				}
			}
		}

        cout<<ans<<'\n';
    }
    return 0;
}
