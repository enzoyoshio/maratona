#include <bits/stdc++.h>

#define int long long

using namespace std;

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> g(n);

    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c; a--, b--;
        g[a].emplace_back(b, c);
    }
    vector<int> dist(n, (int)1e18);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.emplace(0, 0);
    dist[0] = 0;

    while(pq.size()) {
        auto [d, u] = pq.top(); pq.pop();

        if(d > dist[u]) continue;

        for(auto [v, w]: g[u]) {
            if(d + w < dist[v]) {
                dist[v] = d + w;
                pq.emplace(dist[v], v);
            }
        }
    }

    for(auto d: dist) cout << d << ' ';
    cout << endl;
}
