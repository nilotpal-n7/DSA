#include <bits/stdc++.h>
using namespace std;

int main() {
    int t{};
    cin>>t;

    while(t--) {
        int n{}, m{}, a{}, b{};
        cin>>n>>m;
        int points{}, preva{}, prevb{};

        for(int i{}; i<n; i++) {
            cin>>a>>b;
            int interval = a - preva;

            if(interval & 1) {
                if(b == prevb) points += interval - 1;
                else points += interval;
            }
            
            else {
                if(b == prevb) points += interval;
                else points += interval - 1;
            }

            preva = a;
            prevb = b;
        }

        points += m - a;
        cout<<points<<endl;
    }
    return 0;
}
