#include <bits/stdc++.h>
using namespace std;

int main() {
    int t{};
    cin >> t;
    while(t) {
        int n{};
        cin >> n;
        cout << -1;
        if(n & 1) {
            for(int i{2}; i <= n; i++) {
                if(i & 1) cout << " " << -1;
                else cout << " " << 3;
            }
        } else {
            for(int i{2}; i <= n; i++) {
                if(i == n) cout << " " << 2;
                else if(i & 1) cout << " " << -1;
                else cout << " " << 3;
            }
        }
        cout << endl;
        t--;
    }
    return 0;
}
