#include <bits/stdc++.h>
using namespace std;

int main() {
    int t{};
    cin>>t;

    while(t--) {
        int n{};
        cin>>n;
        vector<int> p(n, 0), q(n, 0);

        for(int i{}; i<n; i++) {
            cin>>p[i];
            q[i] = n + 1 - p[i];
        }

        for(int i{}; i<n; i++) cout<<q[i]<<" ";
        cout<<endl;
    }
    return 0;
}
