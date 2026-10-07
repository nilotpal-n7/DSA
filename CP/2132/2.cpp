#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;

        vector<long long> nums;

        int digits = to_string(n).size(); // number of digits
        for (int i = 1; i < digits; i++) {
            long long p = 1;
            for (int j = 0; j < i; j++) p *= 10;  // p = 10^i
            long long d = 1 + p;
            if (n % d == 0) {
                nums.push_back(n / d);
            }
        }

        sort(nums.begin(), nums.end());

        cout << nums.size() << "\n";
        if (!nums.empty()) {
            for (auto q : nums) cout << q << " ";
            cout << "\n";
        }
    }
    return 0;
}
