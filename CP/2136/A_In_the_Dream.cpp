#include <bits/stdc++.h>
using namespace std;

int main() {
    int t{};
    cin >> t;

    while(t--) {
        int a{}, b{}, c{}, d{};
        cin >> a >> b >> c >> d;

        int min1 = min(a, b);
        int max1 = max(a, b);

        if(max1 > 2*(min1 + 1)) cout << "NO" << endl;
        else {
            int e = c - a;
            int f = d - b;

            int min2 = min(e, f);
            int max2 = max(e, f);

            if(max2 > 2*(min2 + 1)) cout << "NO" << endl;
            else cout << "YES" << endl;
        }
    }
    
    return 0;
}
