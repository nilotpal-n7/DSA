#include <bits/stdc++.h>
using namespace std;

int main() {
    int t{};
    cin>>t;

    while(t--) {
        string s{""};
        cin>>s;
        int o{}, z{}, c{};

        for(char c: s) {
            if(c == '0') z++;
            else o++;
        }

        int i{};
        for(i; i<s.size(); i++) {
            if(s[i] == '0') {
                if(o > 0) o--;
                else break;
            }
            else {
                if(z > 0) z--;
                else break;
            }
        }

        cout<<(s.size()-i)<<endl;
    }
    return 0;
}
