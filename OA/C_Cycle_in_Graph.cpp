#include <bits/stdc++.h>
using namespace std;

int n{}, m{}, k{};
vector<vector<int>> ad;
vector<int> pt;
vector<bool> vi;

void dfs() {
    stack<int> st;

    for(int i{1}; i <= n; i++) {
        if(vi[i]) continue;
        st.push(i);
        pt[i] = -1;

        while(!st.empty()) {
            int u = st.top();
            st.pop();
            if (vi[u]) continue;
            vi[u] = true;

            for(int v: ad[u]) {
                if(!vi[v]) {
                    pt[v] = u;
                    st.push(v);
                }

                else if(v != pt[u]) {
                    vector<int> c;
                    int cur = u;
                    c.push_back(v);

                    while(cur != v) {
                        c.push_back(cur);
                        cur = pt[cur];
                    }

                    reverse(c.begin(), c.end());
                    if(c.size() >= k + 1) {
                        cout<<c.size()<<endl;
                        for(int x : c) cout<<x<<" ";
                        cout<<endl;
                        return;
                    }
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>m>>k;
    ad.assign(n+1, vector<int>());
    pt.assign(n+1, -1);
    vi.assign(n+1, false);

    for(int i{}; i<m; i++) {
        int a{}, b{};
        cin>>a>>b;
        ad[a].push_back(b);
        ad[b].push_back(a);
    }

    dfs();
    return 0;
}
