#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;

    while(t--) {
        ll n{}, rK{}, cK{}, rD{}, cD{}, ans{};
        cin>>n>>rK>>cK>>rD>>cD;
        
        if(rK < rD) {
            if(cK < cD) ans = max(rD, cD);
            else if(cK > cD) ans = max(rD, n - cD);
            else ans = rD;
        } else if(rK > rD) {
            if(cK < cD) ans = max(n - rD, cD);
            else if(cK > cD) ans = max(n - rD, n - cD);
            else ans = n - rD;
        } else {
            if(cK < cD) ans = cD;
            else ans = n - cD;
        }

        cout<<ans<<endl;
    }
    return 0;
}
