#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;

    while(t--) {
        int n; cin>>n;
        vector<int> a(n), b;
        for(int i{}; i<n; i++) cin>>a[i];
        b.push_back(a[0]);

        for(int i{1}; i<n; i++) {
            if(a[i] != b.back()) {
                if(b.size() >= 2 && (
                    (b[b.size()-2] <= b.back() && b.back() <= a[i]) ||
                    (b[b.size()-2] >= b.back() && b.back() >= a[i])
                )) {
                    b.pop_back();
                    b.push_back(a[i]);
                    
                }
                else b.push_back(a[i]);
            }
        }

        cout<<b.size()<<"\n";
    }
    return 0;
}
