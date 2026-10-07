#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s{""}, a{""};
    cin>>s;
    char mc{'a'-1};

    for(int i{s.size()-1}; i>=0; i--) {
        if(s[i] >= mc) {
            a += s[i];
            mc = s[i];
        }
    }

    reverse(a.begin(), a.end());
    cout<<a<<endl;
    return 0;
}
