#include <bits/stdc++.h>
using namespace std;

int main() {
    int t{};
    cin >> t;

    while (t--) {
        int k{}, x{};
        cin >> k >> x;
        long long y = x;

        for (int i{}; i < k; i++) {
            if (y > 1 && y % 6 == 4) {
                y = (y - 1) / 3;
            } else {
                y = 2 * y;
            }
        }

        cout << y << endl;
    }
    return 0;
}
