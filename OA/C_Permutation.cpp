#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n{}, k{};
    cin>>n>>k;
    vector<int> a(2*n, 0);

    for(int i{1}; i <= n; i++) {
        if(i <= k) {
            a[2*i - 2] = 2*i;
            a[2*i - 1] = 2*i - 1;
        } else {
            a[2*i - 2] = 2*i - 1;
            a[2*i - 1] = 2*i;
        }
    }

    for(int x : a) cout<<x<<" ";
    return 0;
}
