#include <bits/stdc++.h>
using namespace std;
int oe[4005][4005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n{};
    cin>>n;

    vector<int> b(n, 0);
    for(int &x : b) cin>>x;
    vector<int> v = b;
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    for (int &x : b)
        x = lower_bound(v.begin(), v.end(), x) - v.begin();
    int m = v.size();
    int ans{1};

    for (int i{}; i<n; i++) {
        for (int j{i+1}; j<n; j++) {
            int pre{b[j]}, tar{b[i]}, best{oe[i][pre]};
            if(best == 0) best = 1;

            oe[j][tar] = max(oe[j][tar], best + 1);
            ans = max(ans, oe[j][tar]);
        }
    }

    cout<<ans<<endl;
    return 0;
}
