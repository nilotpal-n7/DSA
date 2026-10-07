#include <bits/stdc++.h>
using namespace std;

bool check_bitwise(int x, int y, int z) {
    for (int bit = 0; bit < 31; bit++) {
        int X = (x >> bit) & 1;
        int Y = (y >> bit) & 1;
        int Z = (z >> bit) & 1;

        bool ok = false;
        for (int A = 0; A <= 1; A++) {
            for (int B = 0; B <= 1; B++) {
                for (int C = 0; C <= 1; C++) {
                    if ( (A & B) == X && (B & C) == Y && (A & C) == Z ) {
                        ok = true;
                        goto next_bit;
                    }
                }
            }
        }
        next_bit:
        if (!ok) return false;
    }
    return true;
}

void solve() {
    int x{}, y{}, z{};
    cin>>x>>y>>z;
    int ans = x & y & z;
    cout<<(check_bitwise(x, y, z) ? "YES" : "NO")<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}
