#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ull a{}, b{};
    cin>>a>>b;

    if((a<b) || ((a-b)&1)) {
        cout<<-1<<endl;
        return 0;
    }

    ull x = (a - b) / 2;
    ull y = a - x;
    if((x&b) == 0) cout<<x<<" "<<y<<endl;
    else cout<<-1<<endl;

    return 0;
}
