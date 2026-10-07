#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n{}, m{};
    cin>>n>>m;
    vector<ll> songs(n, 0);

    for(int i{}; i<n; i++) {
        ll c{}, t{};
        cin>>c>>t;
        if(i == 0) songs[i] = c * t;
        else songs[i] = c * t + songs[i-1];
    }

    int k{};
    for(int i{}; i<m; i++) {
        ll moment;
        cin >> moment;
        while(k < n && songs[k] < moment) k++;
        cout<<k+1<<endl;
    }

    return 0;
}
