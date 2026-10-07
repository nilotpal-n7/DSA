#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n{};
    cin>>n;
    vector<int> nums(n, 0);
    for(int i{}; i<n; i++) cin>>nums[i];

    for(int i{}; i<n/2; i++) {
        if(nums[i]==nums[n-1-i] && nums[i] == i+1) {
            cout<<0<<endl;
            return;
        }
    }

    bool asc{1}, dec{1};
    for(int i{1}; i<n; i++) {
        if(asc && nums[i-1]<=nums[i]) asc = 1;
        else asc = 0;
        if(dec && nums[i-1]>=nums[i]) dec = 1;
        else dec = 0;
    }

    if(!asc && !dec) {
        cout<<0<<endl;
        return;
    } 

    if(n>4 && (nums[2]==n || nums[n-3]==n)) {
        cout<<0<<endl;
        return;
    }

    if(n>3 && (nums[1]==n || nums[n-2]==n)) {
        for(int i{2}; i<n-1; i++) {
            if(nums[i] == nums[i-1]) {
                cout<<0<<endl;
                return;
            }
        }
    }

    if(n!=1 && (nums[0]==n || nums[n-1]==n)) {
        for(int i{1}; i<n; i++) {
            if(nums[i] == nums[i-1]) {
                cout<<0<<endl;
                return;
            }
        }
        cout<<1<<endl;
        return;
    }

    cout<<2<<endl;
    return;
}

int main() {
    int t{};
    cin>>t;
    while(t--) solve();
    return 0;
}
