#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t{};
    cin>>t;

    while (t--) {
        long long x{}, y{}, k{};
        cin>>x>>y>>k;

        long long need = (y+1) * k;
        // Each stick trade increases sticks by x-1
        long long stick_trades = ((need-1) + (x-2)) / (x-1); // x-2 to ceiling divide for x-1
        cout<<stick_trades+k<<'\n';
    }
    return 0;
}
