#include <bits/stdc++.h>

#define int long long

#define db(x) cerr << "[ " << #x << " = " << x << " ]\n"

using namespace std;

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<int> cost(n);
    for(auto& it: cost) cin >> it;

    vector<vector<pair<int,int>>> g(n);

    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b; a--, b--;

        if(cost[a] > cost[b]) {
            g[a].emplace_back(b, 0);
            g[b].emplace_back(a, cost[a]-cost[b]);
        }else {
            g[a].emplace_back(b, cost[b]-cost[a]);
            g[b].emplace_back(a, 0);
        }
    }

    vector<int> dist(n, (int)1e18);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    dist[0] = 0;
    pq.emplace(dist[0], 0);

    while(pq.size()) {
        auto [peso, idx] = pq.top(); pq.pop();

        if(dist[idx] < peso) continue;

        for(auto [idxg, pesog]: g[idx]) {
            if(dist[idxg] > dist[idx] + pesog) {
                dist[idxg] = dist[idx] + pesog;
                pq.emplace(dist[idxg], idxg);
            }
        }
    }

    int ans = 0;
    for(int i = 1; i < n; i++) {
       if(cost[i] < cost[0]) {
           /*
            cout << endl << endl;
            db(i);
            db(cost[i]);
            db(dist[i]);
            */
            ans = max(ans, cost[0]-cost[i] - dist[i]);
       } 
    }

    cout << ans << endl;
}
