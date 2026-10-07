#include <bits/stdc++.h>
using namespace std;

vector<int> transform(int n, const vector<int>& current_a) {
    vector<int> next_a(n);
    for (int i = 0; i < n; ++i) {
        set<int> others;
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            others.insert(current_a[j]);
        }
        
        int mex = 0;
        while (others.count(mex)) {
            mex++;
        }
        next_a[i] = mex;
    }
    return next_a;
}

long long get_sum(const vector<int>& a) {
    long long sum = 0;
    for (int x : a) {
        sum += x;
    }
    return sum;
}

void mexify() {
    int n;
    long long k;
    cin >> n >> k;
    vector<int> a0(n);
    for (int i = 0; i < n; ++i) cin >> a0[i];

    vector<int> a1 = transform(n, a0);
    if (k == 1) {
        cout << get_sum(a1) << endl;
        return;
    }

    vector<int> a2 = transform(n, a1);
    if (a2 == a1) {
        cout << get_sum(a1) << endl;
        return;
    }
    
    if (k == 2) {
        cout << get_sum(a2) << endl;
        return;
    }

    vector<int> a3 = transform(n, a2);
    if ((k - 1) % 2 != 0) cout << get_sum(a2) << endl;
    else cout << get_sum(a3) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) mexify();
    return 0;
}
