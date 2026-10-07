#include <bits/stdc++.h>
using namespace std;
const long long INF = 4e18; 

void chomp_game() {
    int n{};
    cin >> n;
    vector<long long> a(n, 0);
    long long initial_fn{}, max_inc{};
    long long min_odd{INF}, min_even{INF};

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if ((i + 1) % 2 != 0) initial_fn += a[i];
        else initial_fn -= a[i];
    }

    if (n > 1) {
        long long same_parity_increase = (n % 2 == 0) ? (n - 2) : (n - 1);
        max_inc = max(max_inc, same_parity_increase);
    }
    
    for (int i = 0; i < n; ++i) {
        long long r_1based = i + 1;
        long long val = a[i];
        
        // using the current index 'i' as the right side 'r' of a swap
        if (r_1based % 2 != 0) { // r odd, l even
            if (min_even != INF) {
                long long g = (r_1based - 2 * val) - min_even;
                max_inc = max(max_inc, g);
            }
            min_odd = min(min_odd, r_1based + 2 * val);
        }
        else {
            if (min_odd != INF) {
                long long g = (r_1based + 2 * val) - min_odd;
                max_inc = max(max_inc, g);
            }
            min_even = min(min_even, r_1based - 2 * val);
        }
    }

    cout<<initial_fn + max_inc<<endl;
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t{};
    cin>>t;
    while (t--) chomp_game();
    return 0;
}
