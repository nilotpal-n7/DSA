#include <bits/stdc++.h>
using namespace std;

int main() {
    int t{};
    cin>>t;

    while(t) {
        int n{}, m{};
        string a, b, c;
        cin>>n>>a>>m>>b>>c;

        for(int i{}; i<m; i++) {
            if(c[i] == 'D') a = a + b[i];
            else a = b[i] + a;
        }

        cout<<a<<endl;
        t--;
    }
    return 0;
}
