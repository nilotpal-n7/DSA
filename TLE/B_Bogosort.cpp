#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t{};
    cin>>t;

    while(t--) {
        int n{};
        cin>>n;
        vector<int> arr(n);
        for(int i{}; i<n; i++) cin>>arr[i];
        sort(arr.begin(), arr.end(), greater<int>());
        for(int i{}; i<n; i++) cout<<arr[i]<<" ";
        cout<<"\n";
    }

    return 0;
}
