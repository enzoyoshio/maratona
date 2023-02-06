#include <bits/stdc++.h>

using namespace std;

#define int long long

int n;
vector<int> vis;
vector<int> g, custo;
vector<vector<int>> graph(n);

int dfs(int idx) {

    int val = custo[idx];
    vis[idx] = 1;

    for(auto filho: graph[idx]) if(!vis[filho]) {
        val = min(val, dfs(filho));
    } 
    return val;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n;
    g.assign(n, 0);
    custo.assign(n, 0);
    vis.assign(n, 0);
    graph.assign(n, vector<int>());
    for(auto& it: g) cin >> it, it--;
    for(auto& it: custo) cin >> it;

    vector<int> in(n, 0);

    for(int i = 0; i < n; i++) {
        graph[i].push_back(g[i]);
        in[g[i]]++;
    }

    queue<int> q;
    for(int i = 0; i < n; i++) if(in[i] == 0) q.push(i);

    while(q.size()) {
        auto cur = q.front(); q.pop();

        for(auto filho: graph[cur]) {
            in[filho]--;
            if(in[filho] == 0) q.push(filho);
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(!vis[i] && in[i]) {
            ans += dfs(i);
        }
    }
    
    cout << ans << endl;
}
