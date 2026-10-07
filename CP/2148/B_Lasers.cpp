#include <bits/stdc++.h>
using namespace std;

int main() {
    int t{};
    cin>>t;

    while(t--) {
        int n{}, m{}, x{}, y{};
        cin>>n>>m>>x>>y;
        vector<int> a(n, 0), b(m, 0);
        for(int i{}; i<n; i++) cin>>a[i];
        for(int i{}; i<m; i++) cin>>b[i];
        cout<<n+m<<endl;
    }
    return 0;
}
