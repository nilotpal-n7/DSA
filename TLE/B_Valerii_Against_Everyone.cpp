#include <bits/stdc++.h>
using namespace std;

int get() {
    int x{};
    cin>>x;
    return x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t{};
    cin>>t;

    while(t--) {
        int n{};
        cin>>n;
        unordered_set<int> s;
        for(int i{}; i<n; ++i) s.insert(get());
        cout<<(s.size()<n?"YES":"NO")<<"\n";
    }
    return 0;
}
