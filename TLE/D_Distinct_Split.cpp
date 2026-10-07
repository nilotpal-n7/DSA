#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t{};
    cin>>t;

    while(t--) {
        int n{};
        cin>>n;
        string s{};
        cin>>s;

        unordered_map<char, pair<int, int>> loc{};
        for(int i{}; i<n; i++) {
            if(loc.count(s[i])) loc[s[i]].second = i;
            else loc[s[i]] = {i, i};
        }

        unordered_set<char> unique_chars(s.begin(), s.end());
        int total_chars = unique_chars.size();
        int ans{total_chars};

        int left{}, right{total_chars};
        for(int i{}; i<n; i++) {
            if(loc[s[i]].first == i) left++;
            if(loc[s[i]].second == i) right--;
            ans = max(ans, left + right);
        }

        cout<<ans<<"\n";
    };
    return 0;
}
