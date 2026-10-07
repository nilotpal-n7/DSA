#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;

    while(t--) {
        int n; cin>>n;
        int bsize = (n * (n-1)) / 2;
        vector<int> b(bsize);
        for(int i{}; i<bsize; i++) cin>>b[i];
        sort(b.begin(), b.end());

        int x = n-1, i{};
        while(x--) {
            cout<<b[i]<<' ';
            i += (x+1);
        }

        cout<<b.back()<<'\n';
    }
    return 0;
}
