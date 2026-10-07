#include <bits/stdc++.h>
using namespace std;

int spf(int n) {
    if (n % 2 == 0) return 2;
    for (int i = 3; i*i <= n; i += 2)
        if (n % i == 0) return i;
    return n; // prime
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t{};
    cin>>t;

    while(t--) {
        int n{};
        cin>>n;

        if(n & 1) {
            int p = spf(n);
            int a = n / p;
            int b = n - a;
            cout<<a<<" "<<b<<"\n";
        }

        else cout<<n/2<<" "<<n/2<<"\n";
    }
    return 0;
}
