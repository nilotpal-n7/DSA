#include <bits/stdc++.h>
using namespace std;

int main() {
    int t{};
    cin>>t;

    while(t--) {
        int n{};
        cin>>n;

        long long x{}, points{};
        vector<long long> a;
        for (int i{}; i<n; i++) {
            cin>>x;
            points += x;
            if(x & 1) a.push_back(x);
        }

        if (a.empty()) {
            cout<<0<<endl;
            continue;
        }

        sort(a.begin(), a.end());
        
        for(size_t i{}; i < a.size()/2; i++) points -= a[i];
        cout<<points<<endl;
    }
    return 0;
}
