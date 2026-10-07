#include <bits/stdc++.h>
using namespace std;

int main() {
    int t{};
    cin>>t;
    while(t--) {
        int n{};
        cin>>n;
        if(n == 1) cout<<1<<endl;
        else if(n == 2) cout<<9<<endl;
        else if(n == 3) cout<<29<<endl;
        else if(n == 4) cout<<56<<endl;
        else cout<<5*(n*n-n-1)<<endl;
    }
    return 0;
}
