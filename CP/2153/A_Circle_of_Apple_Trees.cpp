#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n{};
    cin>>n;
    unordered_map<int, int> cnt;
    
    for(int i = 0; i < n; ++i) {
        int x{};
        cin>>x;
        cnt[x]++;
    }

    cout<<cnt.size()<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t{};
    cin>>t;
    while(t--) solve();
    return 0;
}
