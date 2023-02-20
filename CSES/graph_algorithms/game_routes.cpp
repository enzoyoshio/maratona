#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MOD = 1e9+7;
int n, m;
vector<vector<int>> g;
vector<int> h;

int dfs(int idx) {
    if(idx == n-1) return 1;

    if(~h[idx]) return h[idx];

    int ans = 0;
    for(auto f: g[idx]) {
        ans = (ans + dfs(f))%MOD;
    }

    return h[idx] = ans;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n >> m;
    g.assign(n, vector<int>());
    h.assign(n, -1);

    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
    }
    cout << dfs(0) << endl;
}
