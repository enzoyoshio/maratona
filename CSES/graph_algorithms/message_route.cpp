#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);

    while(m--) {
        int a, b; cin >> a >> b; a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> dist(n, -1);
    queue<int> q;
    q.push(0);
    dist[0] = 0;
    vector<int> pai(n);
    pai[0] = 0;

    while(q.size()) {
        auto cur = q.front(); q.pop();

        for(auto v: g[cur]) if(dist[v] == -1) {
            dist[v] = dist[cur] + 1;
            q.push(v);
            pai[v] = cur;
        }
    }

    if(dist[n-1] == -1)
        return cout << "IMPOSSIBLE" << endl, 0;

    vector<int> path;
    int cur = n-1;
    while(pai[cur] != cur) {
        path.push_back(cur);
        cur = pai[cur];
    }
    path.push_back(0);
    reverse(path.begin(), path.end());
    cout << path.size() << endl;
    for(auto el: path) 
        cout << el+ 1 << ' ';
    cout << endl;
}
