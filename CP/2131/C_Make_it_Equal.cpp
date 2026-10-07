#include <bits/stdc++.h>
using namespace std;

int main() {
    int t{};
    cin >> t;
    while(t) {
        int n{}, k{}, x{};
        cin >> n >> k;

        unordered_map<int, int> map;
        unordered_map<int, int> map1;
        unordered_map<int, int> map2;

        for(int i{}; i < n; i++) cin >> map1[i];
        for(int i{}; i < n; i++) cin >> map2[i];

        int i = 0;
        while(true) {
            int x1 = map1[i];
            for(int j{}; i<n; j++) {
                if(map2[j] == x1 + k) 
            }
        }

        t--;
    }


    return 0;
}
