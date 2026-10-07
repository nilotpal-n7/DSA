#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;

    while (t--) {
        int n, k;
        cin>>n>>k;
        vector<int> c(n);
        for (int i = 0; i < n; i++) {
            cin >> c[i];
            c[i]--;
        }

        function<bool(int)> brsch = [&](int m) {
            vector<int> last(k, -1);
            vector<pair<int,int>> gap(k, {0, 0});
            // gap[color] = {max_gap, second_max_gap}

            for(int i{}; i<n; i++) {
                int j = c[i];

                if(last[j] == -1)
                    gap[j].first = i;
                else {
                    int g = i-1 - last[j];

                    if (g > gap[j].first) {
                        gap[j].second = gap[j].first;
                        gap[j].first = g;
                    }
                    else if (g > gap[j].second)
                        gap[j].second = g;
                }

                last[j] = i;
            }

            for (int j{}; j<k; j++) {
                if (last[j] == -1) continue;
                int g = n-1 - last[j];

                if (g > gap[j].first) {
                    gap[j].second = gap[j].first;
                    gap[j].first = g;
                }
                else if(g > gap[j].second)
                    gap[j].second = g;
            }

            for(int j{}; j<k; j++) {
                if(last[j] == -1) continue;
                if(gap[j].first <= 2*m + 1&&
                    gap[j].second <= m) return true;
            }

            return false;
        };

        int l{}, r{n-1};
        while(l < r) {
            int m = (l+r) / 2;
            if(brsch(m)) r = m;
            else l = m+1;
        }

        cout<<r<<"\n";
    }
    return 0;
}
