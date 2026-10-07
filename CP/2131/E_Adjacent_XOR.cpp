#include <bits/stdc++.h>
using namespace std;

int main() {
    int t{};
    cin >> t;
    while(t) {
        int n{}, x{}, y{}, z{1};
        cin >> n;
        vector<int> arr(n, 0);
        for(int i{1}; i<n; i++) {
            cin >> x >> y;
            arr[x] += 1;
        }
        for(int i{}; i<n; i++) {
            if(arr[i] == 0) continue;
            z += arr[i] - 1;
        }
        cout << z << endl;
        t--;
    }
    return 0;
}
