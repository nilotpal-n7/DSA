#include <bits/stdc++.h>
using namespace std;

int main() {
    int t{};
    cin>>t;
    while(t) {
        int n{}, g{}, x{};
        cin >> n;
        int nums[n];
        for(int i{}; i < n; i++) cin >> nums[i];
        for(int i{}; i < n; i++) {
            cin >> x;
            if(nums[i] > x) g += nums[i] - x;
        };
        cout << g + 1 << endl;
        t--;
    }
    return 0;
}
