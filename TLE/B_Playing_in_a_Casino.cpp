#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;

    while(t--) {
        int n, m; cin>>n>>m;
        vector<vector<int>> c(m, vector<int>(n));
        for(int i{}; i<n; i++)
            for(int j{}; j<m; j++)
                cin>>c[j][i];

        ll ans{};
        
        for(int i{}; i<m; i++) {
            sort(c[i].begin(), c[i].end());
            for(int j{}; j<n; j++)
                ans += 1LL * c[i][j] * (2LL*j - n+1);
        }

        cout<<ans<<"\n";
    }
    return 0;
}
