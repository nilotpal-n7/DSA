#include <bits/stdc++.h>
using namespace std;

int main() {
    int t{};
    cin>>t;

    while(t--) {
        int n{}, z{}, o{};
        cin>>n;
        string s{""};
        cin>>s;
    
        for(int i{}; i<n; i++) if(s[i] == '0') z++;
        for(int i{}; i<z; i++) if(s[i] == '0') o++;

        cout<<z-o<<endl;
    }
    return 0;
}
