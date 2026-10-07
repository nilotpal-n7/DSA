#include <bits/stdc++.h>
using namespace std;

int main() {
    int t{};
    cin>>t;
    while(t--) {
        int n{}, m{}, c{}, d{};
        cin>>n;
        vector<int> nums(n, 0);

        for(int i{}; i<n; i++) {
            cin>>nums[i];
            m = max(m, nums[i]);
            if(nums[i] != 0) c++;
        }

        d = n-m;
    }
    return 0;
}
