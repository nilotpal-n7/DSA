#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t{};
    cin>>t;

    while(t--) {
        int n{}, m{};
        cin>>n>>m;
        int abs_min = INT_MAX;
        int ngtv_vals{}, zeros{};
        vector<vector<int>> a(n, vector<int>(m));

        for (int i{}; i<n; ++i) {
            for (int j{}; j<m; ++j) {
                int x{};
                cin>>x;
                a[i][j]=x;
                abs_min = min(abs_min, abs(x));
                if (x<0) {
                    ngtv_vals++;
                } else if (x==0) {
                    zeros++;
                }
            }
        }

        long long sum{};
        for (int i{}; i<n; ++i) {
            for (int j{}; j<m; ++j) {
                sum += abs(a[i][j]);
            }
        }

        if(ngtv_vals%2==1 && zeros==0) {
            sum -= 2*abs_min;
        }
        cout<<sum<<"\n";
    }

    return 0;
}