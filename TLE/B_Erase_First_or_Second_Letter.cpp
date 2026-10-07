#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t{};
    cin>>t;

    while(t--) {
        int n{};
        string s{};
        cin>>n>>s;
        vector<int> dp(n, 0);
        dp[n-1] = 1;

        for(int i=n-2; i>=0; i--) {
            if(s[i] != s[i+1]) dp[i] = dp[i+1] + 2;
            else dp[i] = dp[i+1] + 1;
        }

        cout<<dp[0]<<"\n";
    }
    return 0;
}
