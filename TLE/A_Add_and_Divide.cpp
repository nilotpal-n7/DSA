#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t{};
    cin>>t;

    while(t--) {
        int a{}, b{};
        cin>>a>>b;
        if(a < b) cout<<1<<"\n";
        else if(a == b) cout<<2<<"\n";
        else {
            int ans{};

            while(a>0) {
                int ratio = a / b;
                int diff = a - b;
                
            }

            cout<<ans<<"\n";
        }
    }

    return 0;
}
