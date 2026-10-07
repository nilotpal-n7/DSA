#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<long long> l_points(n, 0), r_points(n, 0);
        long long initial_sum_len{}, new_segments_sum_len{};

        for (int i = 0; i < n; ++i) {
            cin>>l_points[i]>>r_points[i];
            initial_sum_len += r_points[i] - l_points[i];
        }

        sort(l_points.begin(), l_points.end());
        sort(r_points.begin(), r_points.end());

        for (int i = 0; i < n / 2; ++i) {
            long long new_len = r_points[n - 1 - i] - l_points[i];
            if (new_len > 0) new_segments_sum_len += new_len;
        }

        cout<<initial_sum_len + new_segments_sum_len<<endl;
    }
    return 0;
}
