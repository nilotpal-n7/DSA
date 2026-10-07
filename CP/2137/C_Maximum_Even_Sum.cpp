#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t{};
    cin >> t;

    while (t--) {
        long long a{}, b{};
        cin >> a >> b;

        if (a % 2 == 0 && b % 2 == 0) { // Both even
            long long sum1 = a + b;
            long long sum2 = a * (b / 2) + 2;
            cout << max(sum1, sum2) << endl;
        } else if (a % 2 == 1 && b % 2 == 1) { // Both odd
            cout << a * b + 1 << endl;
        } else if (a % 2 == 0 && b % 2 == 1) { // a even, b odd
            cout << -1 << endl;
        } else { // a odd, b even
            if (b % 4 != 0) {
                cout << -1 << endl;
            } else {
                long long sum1 = a * 2 + b / 2;
                long long sum2 = a * (b / 2) + 2;
                cout << max(sum1, sum2) << endl;
            }
        }
    }
    return 0;
}
