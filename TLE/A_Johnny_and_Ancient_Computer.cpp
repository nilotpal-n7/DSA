#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t{};
    cin>>t;

    while(t--) {
        ll a{}, b{};
        cin>>a>>b;
        if(a>b) swap(a, b);

        if(a==0 || b==0) {
            if(a==0 && b==0) cout<<0<<'\n';
            else cout<<-1<<'\n';
            continue;
        }

        if(b%a == 0) {
            ll ratio = b/a;
            int ops{};

            while(ratio%2 == 0) {
                if(ratio%8 == 0) ratio /= 8;
                else if(ratio%4 == 0) ratio /= 4;
                else ratio /= 2;
                ops++;
            }

            cout<<(ratio==1 ? ops:-1)<<'\n';
        }
        else cout<<-1<<'\n';
    }
    return 0;
}
