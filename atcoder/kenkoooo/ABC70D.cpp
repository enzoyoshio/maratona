#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 1e5 + 10;
int n, q, k;
vector<pair<int,int>> g[MAXN];
vector<int> dist(MAXN);

void dfs(int u, int v) {
    dist[u] += dist[v];
    for(auto [f, w]: g[u]) if(f != v) {
        dist[f] += w;
        dfs(f, u);
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n;
    for(int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }

    cin >> q >> k;
    dist[k] = 0;
    dfs(k, k);

    for(int i = 0; i < q; i++) {
        int a, b; cin >> a >> b;
        cout << dist[a] + dist[b] << '\n';
    }
}
