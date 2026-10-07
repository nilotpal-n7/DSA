#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t{};
    cin>>t;

    while(t--) {
        int n{}, k{};
        cin>>n>>k;
        vector<int> a(n, 0);
        for(int i{}; i<n; i++) cin>>a[i];
        vector<int> b = a;
        sort(b.begin(), b.end());
        if(k<2 && a!=b) {
            cout<<"NO"<<endl;
            continue;
        }

        cout<<"YES"<<endl;
    }
    return 0;
}
