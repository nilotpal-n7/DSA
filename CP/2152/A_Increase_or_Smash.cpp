#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t{};
    cin>>t;

    while (t--) {
        int n{}, val{};
        cin>>n;
        set<int> nums;

        for (int i = 0; i<n; i++) {
            cin>>val;
            nums.insert(val);
        }

        int k = nums.size();
        cout<<2 * k - 1<<endl;
    }
    
    return 0;
}
